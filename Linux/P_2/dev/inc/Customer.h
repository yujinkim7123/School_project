#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Manager.h"

class Customer {
public:
	void start(Manager& managercall);
	int showmenu(Manager& managercall);
	void menuorder(Manager& managercall);
};
#endif //
