#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
         bool operator()(Event* s1, Event* s2) {
					return (s1->time < s2->time);
				}
} EventLess;
	
#endif
