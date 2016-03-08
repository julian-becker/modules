#ifndef __TASK_H__
#define __TASK_H__

#include <interfaces/ITask.h>
#include <interfaces/Source.h>
#include <interfaces/Sink.h>
#include <utility>
#include <tuple>

template <typename Input, typename Output, typename State>
class Task : public ITask<State> {
	State state;

	Source<Input>& input;
	Sink<Output>& output;

	virtual State createMemento_impl() const final override;
	virtual void applyMemento_impl(const State&) final override;
	virtual void execute_impl() final override;
	virtual std::tuple<State,Output> executeStateTransition_impl(const State& oldState, const Input&) = 0;

public:
	Task(Source<Input>& input, Sink<Output>& output, State state = State{});
};


template <typename Input, typename Output, typename State>
Task<Input,Output,State>
::Task(Source<Input>& input, Sink<Output>& output, State state) 
	: input(input)
	, output(output)
	, state(std::move(state))
{
}

template <typename Input, typename Output, typename State>
State Task<Input,Output,State>
::createMemento_impl() const {
	return state;
}

template <typename Input, typename Output, typename State>
void Task<Input,Output,State>
::applyMemento_impl(const State& newState) {
	state = newState;
}


template <typename Input, typename Output, typename State>
void Task<Input,Output,State>
::execute_impl() {
	Output value;
    std::tie(state,value) = executeStateTransition_impl(state,input.get());
    output.put(value);
}


#endif