




#include <iostream>
#include <string>
#include <list>
#include <thread>
// Need to link with Ws2_32.lib

// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
using namespace std;
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms737591(v=vs.85).aspx
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms737593(v=vs.85).aspx
class ManageSocket
{
	HANDLE hTmr = NULL;
	list<SOCKET*> clnt;
	list<SOCKET*> svrOut;
	SOCKET ListenSocket;

public:

	void ReadUntil(void* socket1)
	{
		SOCKET* socket = (SOCKET*) socket1;
		char out[256] = { 0 };
		int len = 256;
		while (true)
		{
			int lenx = recv(*socket, out, len, 0);
			if (lenx == WSAEWOULDBLOCK)
			{
				cout << "recv() returned WSAEWOULDBLOCK";
			}
			else if (lenx > 0)
			{
				cout << "recv() " << lenx << " bytes";
			}
			else
			{
				cout << "recv() " << lenx << " bytes";
				cout << "exiting ";
				break;
			}
		}
	}

	int acceptUntil()
	{
		while (true)
		{
			// Accept a client socket
			SOCKET* temp = new SOCKET();
			*temp = accept(ListenSocket, NULL, NULL);
			if (*temp == INVALID_SOCKET)
			{
				printf("accept failed with error: %d\n", WSAGetLastError());
				closesocket(*temp);
				WSACleanup();
				return 1;
			}
			else if (*temp == EWOULDBLOCK)
			{
				cout << "accept() will BLOCK";
			}
			else
			{
				cout << "accept() succeded";
				// If iMode = 0, blocking is enabled; 
				// If iMode != 0, non-blocking mode is enabled.
				u_long iMode = 1;
				int iResult = ioctlsocket(*temp, FIONBIO, &iMode);
				if (iResult != NO_ERROR)
					printf("ioctlsocket failed with error: %ld\n", iResult);

				thread* t = new thread(&ManageSocket::SendUntil, this, temp);
			}

			svrOut.push_back(temp);

			//wait for 20ms. If the TIMER is till off go back to  calling ACCEPT
			if (WaitForSingleObject(hTmr, 20) == WAIT_OBJECT_0)
				break;
			return 1;
		}
	}


	int SetupClient(void)
	{
		int iResult;

		SOCKADDR_IN* clientService = new SOCKADDR_IN();
		clientService->sin_family = AF_INET;

		//BYTE adr[256] = { 0 };
		inet_pton(AF_INET, "127.0.0.1", &clientService->sin_addr);
		//clientService->sin_addr.s_addr = &adr[0];
		clientService->sin_port = htons(27015);
		//inet_pton(AF_INET, hostIP, &(sa->sin_addr));
		SOCKET ConnectSocket;
		ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (ConnectSocket == INVALID_SOCKET)
		{
			wprintf(L"socket function failed with error: %ld\n", WSAGetLastError());

			WSACleanup();
			return 1;
		}

		// If iMode = 0, blocking is enabled; 
		// If iMode != 0, non-blocking mode is enabled.
		u_long iMode = 1;
		iResult = ioctlsocket(ConnectSocket, FIONBIO, &iMode);
		if (iResult != NO_ERROR)
			printf("ioctlsocket failed with error: %ld\n", iResult);


	


		while (true)
		{

			// Accept a client socket
			SOCKADDR_IN* temp = new SOCKADDR_IN();
			int Res = connect(ConnectSocket, (SOCKADDR*)clientService, sizeof(*clientService));
			if (Res == SOCKET_ERROR)
			{
				printf("connect() failed with error: %d\n", WSAGetLastError());
				//closesocket((*clientService));
				WSACleanup();
				return 1;
			}
			else if (Res == EWOULDBLOCK)
			{
				cout << "connect() will BLOCK";
			}
			else
			{
				//Launch a thread for Client to read.
				thread* t = new thread(&ManageSocket::ReadUntil, this, &ConnectSocket);

			
			}


			//wait for 20ms. If the TIMER is till off go back to  calling ACCEPT
			if (WaitForSingleObject(hTmr, 20) == WAIT_OBJECT_0)
				break;
			return 1;
		}
	}

	void start()
	{
		try
		{
			//Set a time to expire after 10mins 
			//create server one thread for waiting. 2 for sending and 2 for reading
			//create 4 clients
			TimerS1();
		
			SetupServer();
		
			
			//start listen thread
			thread  Tlsten(&ManageSocket::acceptUntil, this);

			//start connect thread
			thread  Tlsten2(&ManageSocket::SetupClient, this);

			Sleep(1000 * 60 * 60);
			WaitForSingleObject(hTmr, INFINITE);
		
			//close the server sockets
			for (auto s1 = svrOut.begin(); s1 != svrOut.end(); s1++)
			{
				shutdown(**s1, SD_SEND);
				closesocket(**s1);
			}

		}
		catch (...)
		{
		
		}

		WSACleanup();
		
	}

	void TimerS1()
	{
		wstring nName(L"tttt");
		LARGE_INTEGER liDueTime;

		liDueTime.QuadPart = -100000000LL;

		hTmr = CreateWaitableTimer(0, false, nName.c_str());
		if (hTmr != NULL)
		{

			// Set a timer to wait for 10 seconds.
			if (SetWaitableTimer(hTmr, &liDueTime, 0, NULL, NULL, 0))
			{

			}
		}
	}

	

	void SendUntil(void* socket1)
	{
		SOCKET* socket = (SOCKET*)socket1;
		char out[256] = { 0 };
		int len = 256;
		for (int i = 0; i < 256; i++)
			out[i] = i;

		int offset = 0;
		while (true)
		{
			
			int  lenx  = send(*socket, (out + offset), len, 0);
			if (lenx == WSAEWOULDBLOCK)
			{
				cout << "send() returned WSAEWOULDBLOCK";
			}
			else if (lenx == len)
			{
				cout << "send() " << len << " bytes";
				cout << "exiting ";
				break;
			}
			else
			{
				offset = lenx;
				cout << "send() " << len << " bytes";
			}
		}
	}

	
	int SetupServer(void)
	{
		WSADATA wsaData;
		int iResult;
		struct addrinfo *result = NULL;
		struct addrinfo hints;

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0)
		{
			printf("WSAStartup failed with error: %d\n", iResult);
			return 1;
		}

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		// Resolve the server address and port
		iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
		if (iResult != 0) 
		{
			printf("getaddrinfo failed with error: %d\n", iResult);
			WSACleanup();
			return 1;
		}

		// Create a SOCKET for connecting to server
		ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if (ListenSocket == INVALID_SOCKET) 
		{
			printf("socket failed with error: %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();
			return 1;
		}

		// If iMode = 0, blocking is enabled; 
		// If iMode != 0, non-blocking mode is enabled.
		u_long iMode = 1;
		iResult = ioctlsocket(ListenSocket, FIONBIO, &iMode);
		if (iResult != NO_ERROR)
			printf("ioctlsocket failed with error: %ld\n", iResult);


		// Setup the TCP listening socket
		iResult = ::bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
		if (iResult == SOCKET_ERROR) 
		{
			printf("bind failed with error: %d\n", WSAGetLastError());
			freeaddrinfo(result);
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}

		freeaddrinfo(result);

		iResult = listen(ListenSocket, SOMAXCONN);
		if (iResult == SOCKET_ERROR) 
		{
			printf("listen failed with error: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}
	}


	


	
};