#pragma once
/*
	Join() and Detach(). 
	Thread has two parts: thread-object and thread-os-resource.
	thread-object gets created first, and then comes the thread-resource.
	Conversly thread-resource ends first and then thread-object should execute the DTOR.
	If the thread-object wants to exit before the thred-resource, then it should call Detach()
	so that object gets disassociated from the thread-resoucse. Then thread-object can excute to DTOR legally.
	This is how system-threads work. Thread-object may die before the thread-instance.

	But the normal cases, thead-object should wait until thread-resource ends. 
	Then invoke DOTOR of thread-object.
	For this to happen, creator of the thread, should JOIN the current-thread to thread-object,
	so that thread-object waits.
	Now the thread that created the thread-object will wait until the thread-resource ends.
	Once the thread-resource ends, JOIN will end, and thread-object will executes the DTOR.

	NORMALTHREAD_life-cycle
		thread t = new thread(); //create thread-object & thread-resource
		//thread-resource... is running

		t.Join() //Current thread has joined the thread-resource
		//thread-resource... has ended

		//DTOR of threa-object will run
	
	NORMALTHREAD_life-cycle (ILLEGAL)
		thread t = new thread(); //create thread-object & thread-resource
		//thread-resource... is running
		//DTOR of threa-object will run when thread-resource is still running (ILLEGAL)
		//thread-object should have called DETACH() and then exited.


	SYSTEMTHREAD_life-cycle
		thread t = new thread(); //create thread-object & thread-resource
		//thread-resource... is running

		t.detach() //Current thread has DETACHED from the thread-resource
		//DTOR of threa-object will run when thread-resource is still running (LEGAL)


	Thread-ID of the Detached thread()
	---------------------------------
	Thread-object carries the ID of the thread-os-resource as long as Thread-object is ATTACHED to 
	thread-os-resource. Once the thread-object calls DEATCH, it is no longer connected to thread-os-resource,
	then ID becomes default-thread-id.

	http://thispointer.com/c11-multithreading-part-6-need-of-event-handling/
*/