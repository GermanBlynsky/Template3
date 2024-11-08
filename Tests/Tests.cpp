#include "CppUnitTest.h"
#include "..\Solver\List.h"
#include "..\TestClass\Rank.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTest
{
	TEST_CLASS(ListTest)
	{
	public:

		TEST_METHOD(EmptyList_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list;
			Assert::IsTrue(list.IsEmpty());
		}
		TEST_METHOD(PushFrontOneData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1{ 1 };
			LinkedList<int> list2{ 2, 1 };
			list1.push_front(2);
			Assert::IsTrue(list1.toString() == list2.toString());
		}
		TEST_METHOD(PushBackFewData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1 = { 1 };
			LinkedList<int> list2 = { 1, 2 };
			list1.push_back(2);
			Assert::IsTrue(list1.toString() == list2.toString());
		}
		TEST_METHOD(PopFront_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1 = { 2 };
			LinkedList<int> list2 = { 1, 2 };
			list2.pop_front();
			Assert::IsTrue(list1.toString() == list2.toString());
		}
		TEST_METHOD(PopBack_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1 = { 1 };
			LinkedList<int> list2 = { 1, 2 };
			list2.pop_back();
			Assert::IsTrue(list1.toString() == list2.toString());
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////

		TEST_METHOD(PushFrontOneData_Success_TestClass)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1{ NoRank };
			LinkedList<Rank> list2{ CandidatRank, NoRank };
			list1.push_front(CandidatRank);
			Assert::IsTrue(list1.toString() == list2.toString());
		}
		TEST_METHOD(PushBackFewData_Success_TestClass)
		{
			using namespace uizi;
			using namespace rut_miit;
			LinkedList<Rank> list1 = { NoRank };
			LinkedList<Rank> list2 = { NoRank, CandidatRank };
			list1.push_back(CandidatRank);
			Assert::IsTrue(list1.toString() == list2.toString());
		}
		TEST_METHOD(PopFront_ValidData_Success_TestClass)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1 = { CandidatRank };
			LinkedList<Rank> list2 = { NoRank, CandidatRank };
			list2.pop_front();
			Assert::IsTrue(list1.toString() == list2.toString());
		}
		TEST_METHOD(PopBack_ValidData_Success_TestClass)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1 = { NoRank };
			LinkedList<Rank> list2 = { NoRank, CandidatRank };
			list2.pop_back();
			Assert::IsTrue(list1.toString() == list2.toString());
		}
	};
}