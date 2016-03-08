#ifndef __ITASK_H__
#define __ITASK_H__

#include <interfaces/IExecutable.h>
#include <interfaces/IMemorizable.h>

template <typename State>
struct ITask 
	: IMemorizable<State>
	, IExecutable 
{
};

#endif