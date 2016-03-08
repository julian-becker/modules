#ifndef __IIDENTIFYABLE_H__
#define __IIDENTIFYABLE_H__

template <typename ID_T>
struct IIdentifyable {
	virtual ~IIdentifyable() {}
	ID_T get_id() const { return get_id_impl(); }
	
private:
	virtual ID_T get_id_impl() const = 0;
};

#endif