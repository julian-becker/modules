#ifndef __IMEMORIZABLE_H__
#define __IMEMORIZABLE_H__

template <typename State>
struct IMemorizable {
	virtual ~IMemorizable() {}
	State createMemento() const { return createMemento_impl(); }
	void applyMemento(const State& memento) { applyMemento_impl(memento); }

private:
	virtual State createMemento_impl() const = 0;
	virtual void applyMemento_impl(const State&) = 0;
};

#endif