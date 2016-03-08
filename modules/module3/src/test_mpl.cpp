#include <mpl/mpl_assert.h>
#include <module.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <iostream>
#include <list>
#include <chrono>
#include <iterator>
#include <functional>
#include <vector>

#include <Digraph.h>
#include <sstream>
#include <functional>

#include <interfaces/ITask.h>
#include <interfaces/IIdentifyable.h>

#include <Task.h>


struct TestSource final : Source<int> {
	int state = 0;
private:
	virtual int get_impl() override { return state++; }
};

struct TestSink final : Sink<std::string> {
private:
	virtual void put_impl(const std::string& value) override {
		std::cout << "sink: " << value << std::endl;
	}
};

struct TestTask final : Task<int,std::string,int> {
	TestTask() 
		: Task<int,std::string,int>(input,output,42)
	{}

private:
	TestSource input;
	TestSink output;

	virtual std::tuple<int,std::string> executeStateTransition_impl(const int& state, const int& value) override {
		std::stringstream s; s << "state=" << state << ", value=" << value;
		return std::make_tuple(state+value,s.str());
	}
};



void run_mpl_tests() {
    TestTask t;
    t.execute();
    t.execute();
    t.execute();

	TestSource input;
	TestSink output;
}
























using testIntEqualsInt = Assert::are_equal<int,int>;
using testIntNotEqualsDouble = Assert::are_different<int,double>;
using testTrue = Assert::is_true<true>;
