#ifndef __IEXECUTABLE_H__
#define __IEXECUTABLE_H__

struct IExecutable {
	virtual ~IExecutable() {}
	void execute() { execute_impl(); }

private:
	virtual void execute_impl() = 0;
};

#endif