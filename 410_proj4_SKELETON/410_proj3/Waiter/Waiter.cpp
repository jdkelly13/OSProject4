#include <string>
#include "stdlib.h"
#include "..\includes\externs.h"
#include "..\includes\Waiter.h"

using namespace std;

//Waiter Constructor.
Waiter::Waiter(int id,std::string filename):id(id),myIO(filename){
	Waiter::id = id;
	Waiter::myIO = File_IO(filename);
}

//Waiter Destructor.
Waiter::~Waiter()
{
}

//gets next Order(s) from file_IO.
int Waiter::getNext(ORDER &anOrder){
	return myIO.getNext(anOrder);
}

//Does Waiter things.
void Waiter::beWaiter() {
	//Temp variables for use in beWaiter.
	int ret;
	ORDER anOrder;
	bool loopBreak = true;

	while (loopBreak) {
		//Grabs the next order and saves it as anOrder.
		ret = getNext(anOrder);

		switch (ret)
		{
		case SUCCESS:
			order_in_Q.push(anOrder);
			cv_order_inQ.notify_all;
			break;
		case FAIL:

			break;
		case NO_ORDERS:
			b_WaiterIsFinished = true;
			loopBreak = false;
			break;
		}
		
	}
}

