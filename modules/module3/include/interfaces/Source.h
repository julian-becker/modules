#ifndef __SOURCE_H__
#define __SOURCE_H__

template <typename T> 
struct Source {
	virtual ~Source() {}
	T get() { return get_impl(); }
private:
	virtual T get_impl() = 0;
};

#endif