#ifndef __SINK_H__
#define __SINK_H__

template <typename T> 
struct Sink {
	virtual ~Sink() {}
	void put(const T& value) { put_impl(value); }
private:
	virtual void put_impl(const T&) = 0;
};

#endif