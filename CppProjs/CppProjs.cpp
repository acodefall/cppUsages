// CppProjs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RefConstTest.h"
#include "FriendTest.h"
#include "CopyCtor.h"
#include "ConstError.h"
#include "SmartPtr1.h"
#include "MutexTest.h"
#include "ConstantPointerTest.h"
#include "RTTICasting.h"
#include "SmartPointerTest.h"
#include "OverLoadIndexOp.h"
#include "SizeofX.h"
#include "PostFixPreFixOverload.h"
#include "FindIf.h"
#include "LambdaCaptureList.h"
#include "LambdaInplaceFuncPointer.h"
#include "SharedPointerUsage.h"
#include "CopyCTORCalling.h"
//#include "SocketW.h"
#include "BootStrap.h"
#include "PriorityQUsage.h"
#include "SetComparison.h"
#include "SortPredicateForMap.h"
#include "PriorityQueueUsage.h"
#include "PaddingCout.h"
#include "FactorialRecursion.h"
#include "MapFunction.h"
#include "AppendCharToString.h"
#include "ArrayToPointerCoversion.h"
#include "SearchPredicateForList.h"
#include "SortPredicateForList.h"
#include "SortPredicateForSet.h"
#include "stringOperation.h"
#include "PrintBitsUsingBitSet.h"
#include "PrintHexDec.h"
#include "SetUsage.h"
#include "StaticClass.h"
#include "ThreadClassMemberWorker.h"
#include "ThreadStaticWorker.h"
#include "ThreadWorkerGlobal.h"
#include "Syncq.h"
#include "ObjectPoolArc.h"
#include "UsingList.h"
#include "FactoryCreate.h"
#include "ProtectedCtor.h"
#include "OrderOfInit.h"
#include "ReaderWriter.h"
#include "RotateMatrix90.h"
#include "FindDistinctIsland.h"
#include "SearchWordInMatrix.h"
#include "SmartPointerArc.h"

BootStrapX gblBootStrapX;
int _tmain(int argc, _TCHAR* argv[])
{
	SmartPointerArcNM::useSmartPointerArcC objuseSmartPointerArcC;
	objuseSmartPointerArcC.create();

	FactoryCreateNM::useMailServer  objuseMailServer;
	objuseMailServer.createMailServers();

	SearchWordInMatrixNM::SearchWordInMatrix objSearchWordInMatrix;
	objSearchWordInMatrix.SearchWordInMatrixX();

	FindDistinctIslandNM::FindDistinctIsland objFindDistinctIsland;
	objFindDistinctIsland.callFindDistinctIsland();

	RotateMatrix90NM::RotateMatrix objRotateMatrix90;
	objRotateMatrix90.rotate();

	//ReaderWriterNM::RdWr objRdWr;
	//objRdWr.CreateThreads();

	RefConstTest objRefConstTest;
	objRefConstTest.callRefConstTest2();

	OrderOfInitNM::testOrderInit objtestOrderInit;
	objtestOrderInit.calltestOrderInit();

	ProtectedCtorNM::callProtectedCtorArc objcallProtectedCtorArc;
	objcallProtectedCtorArc.test();



	UsingListNM::UsingListC objUsingListC;
	objUsingListC.callUsingListC();

	ObjectPoolArcNM::callObjectPoolArc objcallObjectPoolArc;
	objcallObjectPoolArc.createThread();

	SyncQNM::callSyncQArc objSyncQArc;
	objSyncQArc.createThreads();

	StaticClassNM::useStaticClass objuseStaticClass;
	objuseStaticClass.createThreads();

	ThreadWorkerGlobalNM::ThreadWorkerGlobal objThreadWorkerGlobal;
	objThreadWorkerGlobal.createThreads();

	ThreadStaticWorkerNM::ThreadStaticWorker objThreadStaticWorker;
	objThreadStaticWorker.createThreads();

	ThreadClassMemberWorkerNM::ThreadMemberWorker objThreadMemberWorker;
	objThreadMemberWorker.createThreads();

	

	SetUsageNM::testSetUsage	objtestSetUsage;
	objtestSetUsage.callsetSimpleUsage();

	stringOperationNM::stringOperation objstringOperation;
	objstringOperation.callstringOperation();

	PrintBitsUsingBitSetNM::PrintBitsUsingBitSet objPrintBitsUsingBitSet;
	objPrintBitsUsingBitSet.callPrintBitsUsingBitSet();

	PrintHexDecNM::PrintHexDec objPrintHexDec;
	objPrintHexDec.callPrintHexDec();


	SharedPointerUsageNM::SharedPointerUsage objSharedPointerUsage;
	objSharedPointerUsage.callSharedPointerUsage();


	

	SortPredicateForSetNM::SortPredicateForSet objSortPredicateForSet;
	objSortPredicateForSet.callSortPredicateForSet();

	SortPredicateForMapNM::SortPredicateForMap  objSortPredicateForMap;
	objSortPredicateForMap.callSortPredicateForMap();

	SortPredicateForListNM::SortPredicateForList objSortPredicateForList;
	objSortPredicateForList.callSortPredicateForList();

	SearchPredicateForListNM::SearchPredicateForList objSearchPredicateForList;
	objSearchPredicateForList.callSearchPredicateForList();

	

	ArrayToPointersNM::ArrayToPointers objArrayToPointers;
	objArrayToPointers.Test();

	PriorityQueueUsageNM::PriorityQueueUsage objPriorityQueueUsage;
	objPriorityQueueUsage.callPriorityQueueUsage();
	objPriorityQueueUsage.callPriorityQueueUsagePlainInt();

	AppendToStringNM::AppendCharToString objAppendCharToString;
	objAppendCharToString.callAppendCharToString();

	MapFunctionsNM::MapFunctions  objMapFunctions;
	objMapFunctions.callMapFunctions();


	PaddingCoutNM::PaddingCout objPaddingCout;
	objPaddingCout.CallPaddingCout();
	
	

	LambdaInplaceFuncPointerNM::TestLambdaInplaceFuncPointer objLambdaInplaceFuncPointer;
	objLambdaInplaceFuncPointer.callLambdaInplaceFuncPointer();

	CaptureListOfLambdaNM::TestCaptureListOfLambda objTestCaptureListOfLambda;
	objTestCaptureListOfLambda.callCaptureListOfLambda();

	UsingFindIfNM::TestFindIf objTestFindIf;
	objTestFindIf.callTestFindIf();

	testDynamicCasting objtestDynamicCasting;
	objtestDynamicCasting.calltestDynamicCasting();

	smartTest xsmartTest;
	xsmartTest.uniqueTest();
	

	TestCpCtor objTestCpCtor;
	objTestCpCtor.callTestCpCtor();

	callTestFixes objcallTestFixes;
	objcallTestFixes.callTestFixesX();

	SizeofX objSizeofX;
	objSizeofX.callSizeof();

	OIndexX objOIndexX;
	objOIndexX.callOIndex();

	
	PtrTest1 objPtrTest1;
	//objPtrTest1.callPtrTest1();
	//objPtrTest1.callPtrTest2();
	objPtrTest1.callPtrTest3();
	objPtrTest1.callPtrTest4();
	objPtrTest1.callPtrTest5();

	FriendTest objFriendTest;
	objFriendTest.callFriendTest();
	objFriendTest.callFriendTest2();


	MutexTest objMutexTest;
	objMutexTest.callMutexTest();

	SmartPtrTest objSmartPtrTest;
	objSmartPtrTest.callSmartPtrTest();

	
	



	printf("\r\n");
	CopyCtorTest objCopyCtorTest;
	objCopyCtorTest.callCopyCtorTest1();
	objCopyCtorTest.callCopyCtorTest2();

	ConstErrorTest objConstErrorTest;
	objConstErrorTest.callConstErrorTest();




	SetComparisonNM::testSetComparisonNM objtestSetComparisonNM;
	objtestSetComparisonNM.SetComparisonNM();

	
	
	UsageOfPrioriQNm::TestUsageOfPriorotyQ objTestUsageOfPriorotyQ;
	objTestUsageOfPriorotyQ.callTestingUsageOfPriorityQ();
	
	int a = 78;
	int* b = &a;
	printf("%d", b);
	return 0;
}

