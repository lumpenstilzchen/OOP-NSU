#include <iostream>

class Thermometer {
	int factory_id;
	int cur_set_id;
	double cur_temp;
	double previous_temp_set[10];
	
	public:	
		Thermometer() = default; // default

		Thermometer(int factory_id, int cur_set_id, double cur_temp, double *previous_temp_set):	// initialization
			factory_id(factory_id), cur_set_id(cur_set_id), cur_temp(cur_temp), previous_temp_set(previous_temp_set) {}
			
		Thermometer(const Thermometer& t) {		// copy
			this->factory_id = t.factory_id;
			this->cur_set_id = t.cur_set_id;
			this->cur_temp = t.cur_temp;
			this->previous_temp_set = t.previous_temp_set;
		}


};
