#include "CppUnitTest.h"
#include "..\Solver\List.h"
#include "..\TestClass\Rank.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTest
{
	TEST_CLASS(ListTest)
	{
	public:

		TEST_METHOD(EmptyIntDoublyLinkedList_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list;
			Assert::IsTrue(list.is_empty());
		}
		TEST_METHOD(PushFrontOneTimeInt_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1{ 1 };
			LinkedList<int> list2{ 2, 1 };
			list1.push_front(2);
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}
		TEST_METHOD(PushBackOneTimeInt_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1 = { 1 };
			LinkedList<int> list2 = { 1, 2 };
			list1.push_back(2);
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}
		TEST_METHOD(PopFrontInt_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1 = { 2 };
			LinkedList<int> list2 = { 1, 2 };
			list2.pop_front();
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}
		TEST_METHOD(PopBackInt_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1 = { 1 };
			LinkedList<int> list2 = { 1, 2 };
			list2.pop_back();
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}

		TEST_METHOD(MoveConstructorInt_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1{ 1,2,3 };
			LinkedList<int> list2(std::move(list1));
			Assert::AreEqual(list2.get_head_value(), 1);
			list2.pop_front();
			Assert::AreEqual(list2.get_head_value(), 2);
			Assert::AreEqual(list2.get_tail_value(), 3);
		}

		TEST_METHOD(OperatorMoveInt_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList list1{ 1,2 }, list2 = std::move(list1);
			Assert::IsTrue(list2.get_head_value() == 1 && list2.get_tail_value() == 2);
		}

		TEST_METHOD(EqualLinkedListesConstructionInt_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1={ 1,2,3 };
			LinkedList<int> list2(list1);
			Assert::AreEqual(list1.get_head_value(), list2.get_head_value());
			Assert::AreEqual(list1.get_tail_value(), list2.get_tail_value());
			list1.pop_front();
			list2.pop_front();
			Assert::IsTrue(list1.get_head_value() == list2.get_head_value());
		}
		
		TEST_METHOD(EqualLinkedListesByOperatorInt_ValidData_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1={ 1,2,3 };
			LinkedList<int> list2 = list1;
			Assert::AreEqual(list1.get_head_value(), list2.get_head_value());
			Assert::AreEqual(list1.get_tail_value(), list2.get_tail_value());
			list1.pop_front();
			list2.pop_front();
			Assert::AreEqual(list1.get_head_value(), list2.get_head_value());
		}

		TEST_METHOD(Insert_ValidIndex_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1{ 1, 2, 3 };
			LinkedList<int> list2{ 1, 4, 2, 3,  };
			list1.insert(1, 4);
			Assert::AreEqual(list1.get_head_value(), list2.get_head_value());
		}

		TEST_METHOD(Insert_InvalidIndex_Throw)
		{
			using namespace rut_miit;
			LinkedList<int> list{ 1, 2, 3 };
			Assert::ExpectException<std::out_of_range>([&]() { list.insert(4, 4); });
		}

		TEST_METHOD(Remove_ValidIndex_Success)
		{
			using namespace rut_miit;
			LinkedList<int> list1{ 1, 2, 3 };
			LinkedList<int> list2{ 1, 4, 2, 3, };
			list2.remove(1);
			Assert::AreEqual(list1.get_head_value(), list2.get_head_value());
		}

		TEST_METHOD(Remove_InvalidIndex_Throw)
		{
			using namespace rut_miit;
			LinkedList<int> list{ 1, 2, 3 };
			Assert::ExpectException<std::out_of_range>([&]() { list.remove(4); });
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////

		TEST_METHOD(PushFrontOneTimeTestClass_ValidData_Success)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1{ NoRank };
			LinkedList<Rank> list2{ CandidatRank, NoRank };
			list1.push_front(CandidatRank);
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}
		TEST_METHOD(PushBackOneTimeTestClass_ValidData_Success)
		{
			using namespace uizi;
			using namespace rut_miit;
			LinkedList<Rank> list1 = { NoRank };
			LinkedList<Rank> list2 = { NoRank, CandidatRank };
			list1.push_back(CandidatRank);
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}
		TEST_METHOD(PopFront_ValidData_Success_TestClass)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1 = { CandidatRank };
			LinkedList<Rank> list2 = { NoRank, CandidatRank };
			list2.pop_front();
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}
		TEST_METHOD(PopBackTestClass_ValidData_Success)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1 = { NoRank };
			LinkedList<Rank> list2 = { NoRank, CandidatRank };
			list2.pop_back();
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}

		TEST_METHOD(MoveConstructorTestClass_ValidData_Success)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1{ NoRank ,CandidatRank,DoctorRank };
			LinkedList<Rank> list2(std::move(list1));
			LinkedList<Rank> list3{CandidatRank,DoctorRank };
			list2.pop_front();
			Assert::IsTrue(list2.to_string() == list3.to_string());
		}

		TEST_METHOD(OperatorMoveTestClass_ValidData_Success)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1{ NoRank , CandidatRank };
			LinkedList<Rank> list2 = std::move(list1);
			Assert::IsTrue(list2.get_head_value() == NoRank && list2.get_tail_value() == CandidatRank);
		}

		TEST_METHOD(EqualLinkedListesConstructionTestClass_ValidData_Success)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1 = { NoRank,CandidatRank, DoctorRank };
			LinkedList<Rank> list2(list1);
			list1.pop_front();
			list2.pop_front();
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}

		TEST_METHOD(EqualLinkedListesByOperatorTestClass_ValidData_Success)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1 = { NoRank,CandidatRank,DoctorRank };
			LinkedList<Rank> list2 = list1;
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}

		TEST_METHOD(Insert_ValidIndex_Success_TestClass)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list1{ NoRank, CandidatRank };
			LinkedList<Rank> list2{ NoRank, DoctorRank, CandidatRank };
			list1.insert(1, DoctorRank);
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}

		TEST_METHOD(Insert_InvalidIndex_Throw_TestClass)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list{ NoRank, CandidatRank};
			Assert::ExpectException<std::out_of_range>([&]() { list.insert(4, CandidatRank); });
		}

		TEST_METHOD(Remove_ValidIndex_Success_TestClass)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<int> list1{ NoRank, DoctorRank, CandidatRank };
			LinkedList<int> list2{ NoRank, CandidatRank };
			list1.remove(1);
			Assert::IsTrue(list1.to_string() == list2.to_string());
		}

		TEST_METHOD(Remove_InvalidIndex_Throw_TestClass)
		{
			using namespace rut_miit;
			using namespace uizi;
			LinkedList<Rank> list{ NoRank, CandidatRank };
			Assert::ExpectException<std::out_of_range>([&]() { list.remove(4); });
		}

	};
}