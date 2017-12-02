// CppProjs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RefConstTest.h"
#include "FriendTest.h"
#include "CopyCtor.h"
#include "ConstError.h"
#include "Thread1.h"
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

BootStrapX gblBootStrapX;
int _tmain(int argc, _TCHAR* argv[])
{
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

	RefConstTest objRefConstTest;
	objRefConstTest.callRefConstTest1();
	



	printf("\r\n");
	CopyCtorTest objCopyCtorTest;
	objCopyCtorTest.callCopyCtorTest1();
	objCopyCtorTest.callCopyCtorTest2();

	ConstErrorTest objConstErrorTest;
	objConstErrorTest.callConstErrorTest();

	Thread1Test objThread1Test;
	objThread1Test.callThread1Test();


	SetComparisonNM::testSetComparisonNM objtestSetComparisonNM;
	objtestSetComparisonNM.SetComparisonNM();

	
	
	UsageOfPrioriQNm::TestUsageOfPriorotyQ objTestUsageOfPriorotyQ;
	objTestUsageOfPriorotyQ.callTestingUsageOfPriorityQ();
	
	int a = 78;
	int* b = &a;
	printf("%d", b);
	return 0;
}

