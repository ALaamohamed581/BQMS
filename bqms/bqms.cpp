
#include <iostream>;
#include <string>
struct Time {
	int hours;
	int minutes;
};
int amountOfCustomersINBankcustomes;




struct details {
	Time arrivel_time;
	Time service_time;
	Time departure_time;
	Time waiting;

};
//globaltvbles
int waitingcustomers = 0;
Time waitTime;
Time TotalServiceTimeIntheBak;
using namespace std;




//bacnk Quea data
class customer
{
public:
	customer* next;
	details da;
	int prority;

	customer(details Data) {

		next = NULL;
		this->da.arrivel_time.hours = Data.arrivel_time.hours;
		this->da.arrivel_time.minutes = Data.arrivel_time.minutes;
		this->da.service_time.minutes = Data.service_time.minutes;

	}


};

class  queue
{
public:
	customer* hea, * rear;
	queue() {
		hea = rear = NULL;
	}
	void enqueue(details Data) {
		customer* n1 = new customer(Data);
		if (hea == NULL) {
			hea = rear = n1;
		}
		else
		{
			rear->next = n1;

			rear = n1;
		}
	};

	void display() {
		customer* customer = hea;
		while (customer != NULL)
		{
			cout << customer->da.arrivel_time.hours << customer->da.arrivel_time.minutes << "\t";
			customer = customer->next;
		}
	};
	int size() {
		int size = 0;
		customer* curret = hea;
		while (curret != NULL)
		{
			size++;
			curret = curret->next;
		}
		return size;
	};
	void bublesort() {
		int it = 0;
		int s = size();
		int itrtitions = 0;
		customer* current = hea;

		for (int j = 0; j < s - 1; j++)
		{
			current = hea;
			for (int i = 0; i < s - 1; i++)
			{
				if (current->da.arrivel_time.hours > current->next->da.arrivel_time.hours) {

					swap(current->da.arrivel_time, current->next->da.arrivel_time);

				}
				else if (current->da.arrivel_time.hours == current->next->da.arrivel_time.hours && current->da.arrivel_time.minutes > current->next->da.arrivel_time.minutes)
				{
					swap(current->da.arrivel_time, current->next->da.arrivel_time);

				}


				current = current->next;
				it++;
			}

			current = current->next;

		}
	}

	int dequeue() {
		customer* customer = hea;

		if (hea == rear) {
			hea = rear = NULL;
		}
		else {
			hea = hea->next;

			delete customer;

		}


		return 1;

	};



};

// Bank Tellers data

class node {
public:
	node* Prev, * next;
	int Data;
	int mode = 0;
	Time customerBeingSerrved;
	Time sustormearrivetime;
	Time customerDepatureTime;
	Time CustomerWaitTiem;
	string name;
	float CustomesServed = 0;

	node(int data) {
		this->Data = data;
		next = Prev = NULL;
	}
};

class linked_list {
public:
	node* head, * tail;

	linked_list() {
		head = tail = NULL;

	}
	void add(int data) {
		node* nodee = new node(data);
		if (head == NULL)
		{
			head = tail = nodee;
		}
		else {
			tail->next = nodee;
			nodee->Prev = tail;
			tail = nodee;
		}
	}
	int firstCustomerToLeave() {


		node* current = head;
		int leesttime = current->customerDepatureTime.minutes;
		while (current != NULL)
		{
			if (current->customerDepatureTime.minutes < leesttime) {
				leesttime = current->customerDepatureTime.minutes;
			}
			current = current->next;
		}
		return leesttime;
	}

	int size() {
		int size = 0;
		node* curret = head;
		while (curret != NULL)
		{
			size++;
			curret = curret->next;
		}
		return size;
	}

	void bublesort() {
		int s = size();
		int itrtitions = 0;
		node* current = head;

		for (int j = 0; j < s - 2; j++)
		{
			current = head;
			for (int i = 0; i < s - 1; i++)
			{
				if (current->Data > current->next->Data) {

					swap(current->Data, current->next->Data);

				}

				current = current->next;

			}

			current = current->next;


		}



	}

	void  srvingsustomers(queue& bank) {

		node* current = head;
		customer* vip = bank.hea;

		//while (vip != NULL)

		//{
		//	if (vip->prority == 2) {
		//		current->mode = 1;
		//		current->sustormearrivetime.hours = bank.hea->da.arrivel_time.hours;
		//		current->sustormearrivetime.minutes = bank.hea->da.arrivel_time.minutes;

		//		current->customerBeingSerrved.minutes = bank.hea->da.service_time.minutes;
		//		current->customerDepatureTime.hours = bank.hea->da.arrivel_time.hours;
		//		current->customerDepatureTime.minutes = bank.hea->da.service_time.minutes + bank.hea->da.arrivel_time.minutes;
		//		current = current->next;
		//	}
		//	vip = vip->next;
		//
		//}

		if (current->mode == 0) {
			while (current != NULL && bank.hea != NULL) {
				current->mode = 1;




				current->sustormearrivetime.hours = bank.hea->da.arrivel_time.hours;
				current->sustormearrivetime.minutes = bank.hea->da.arrivel_time.minutes;

				current->customerBeingSerrved.minutes = bank.hea->da.service_time.minutes;

				current->customerDepatureTime.hours = bank.hea->da.arrivel_time.hours;
				current->customerDepatureTime.minutes = bank.hea->da.service_time.minutes + bank.hea->da.arrivel_time.minutes;


				bank.dequeue();
				currentStatus(current);
				current->CustomesServed++;
				current = current->next;


			}




		}

		else if (current->mode == current->next->mode == current->next->next->mode == 1) {

			if (current->sustormearrivetime.hours == current->next->sustormearrivetime.hours && current->sustormearrivetime.hours == current->next->next->sustormearrivetime.hours && current->sustormearrivetime.hours == bank.hea->da.arrivel_time.hours) {

				if (bank.hea->da.arrivel_time.minutes > current->customerDepatureTime.minutes || bank.hea->da.arrivel_time.minutes > current->customerDepatureTime.minutes || bank.hea->da.arrivel_time.minutes > current->next->customerDepatureTime.minutes || bank.hea->da.arrivel_time.minutes > current->next->next->customerDepatureTime.minutes) {

					while (current != NULL)
					{
						if (current->customerDepatureTime.minutes < bank.hea->da.arrivel_time.minutes) {
							current->mode = 0;
							current->sustormearrivetime.hours = bank.hea->da.arrivel_time.hours;
							current->sustormearrivetime.minutes = bank.hea->da.arrivel_time.minutes;

							current->customerBeingSerrved.minutes = bank.hea->da.service_time.minutes;

							current->customerDepatureTime.hours = bank.hea->da.arrivel_time.hours;
							current->customerDepatureTime.minutes = bank.hea->da.service_time.minutes + bank.hea->da.arrivel_time.minutes;
							current->mode = 1;
							bank.dequeue();
							current->CustomesServed++;
							currentStatus(current);
						}

						current = current->next;
					}
				}
				else
				{



					int leestserviceAmout = firstCustomerToLeave();


					while (current != NULL && bank.hea != NULL)
					{



						if (current->customerDepatureTime.minutes == leestserviceAmout) {

							bank.hea->da.waiting.minutes = bank.hea->da.arrivel_time.minutes - leestserviceAmout;
							if (bank.hea->da.waiting.minutes < 0) {
								bank.hea->da.waiting.minutes = bank.hea->da.waiting.minutes * -1;
							}

							current->mode = 0;
							current->customerBeingSerrved.minutes = bank.hea->da.service_time.minutes;

							current->customerDepatureTime.hours = bank.hea->da.arrivel_time.hours + current->CustomerWaitTiem.hours + current->customerBeingSerrved.hours;
							current->customerDepatureTime.minutes = bank.hea->da.arrivel_time.minutes + bank.hea->da.waiting.minutes + bank.hea->da.service_time.minutes;

							current->sustormearrivetime.hours = bank.hea->da.arrivel_time.hours;
							current->sustormearrivetime.minutes = bank.hea->da.arrivel_time.minutes;
							current->CustomerWaitTiem.minutes = bank.hea->da.waiting.minutes;
							current->customerBeingSerrved.hours = bank.hea->da.service_time.hours;
							current->customerBeingSerrved.minutes = bank.hea->da.service_time.minutes;
							current->mode = 1;


							currentStatus(current);
							current->CustomesServed++;
							waitTime.minutes += bank.hea->da.waiting.minutes;
							waitingcustomers++;
							bank.dequeue();
						}

						current = current->next;


					}
				};
			}
			else {

				while (bank.hea != NULL) {
					current->mode = 0;

					current->customerBeingSerrved.minutes = bank.hea->da.service_time.minutes;
					current->sustormearrivetime.hours = bank.hea->da.arrivel_time.hours;
					current->sustormearrivetime.minutes = bank.hea->da.arrivel_time.minutes;

					current->customerDepatureTime.hours = bank.hea->da.service_time.hours + bank.hea->da.arrivel_time.hours;
					current->customerDepatureTime.minutes = bank.hea->da.service_time.minutes + bank.hea->da.arrivel_time.minutes;
					bank.dequeue();

					current->mode = 1;
					currentStatus(current);
					current->CustomesServed++;
					current = current->next;
				}
			}






		}
	}


	void customesrServedByeachTeller(int amout) {
		node* current = head;
		while (current != NULL) {
			cout << current->name << " :";


			cout << (current->CustomesServed / amout) * 100 << '%' << "\t";
			current = current->next;
		}

		cout << "\n";
	}


	void currentStatus(node* c) {

		Time Times[5] = { c->sustormearrivetime,c->customerBeingSerrved,c->customerDepatureTime,c->CustomerWaitTiem };
		TotalServiceTimeIntheBak.minutes += Times[1].minutes;
		for (int i = 0; i < 5; i++) {
			if (Times[i].minutes > 59) {
				Times[i].hours += Times[i].minutes / 60;
				Times[i].minutes = Times[i].minutes % 60;
			}


		}



		cout << "\n";
		cout << "TellerName " << c->name << "\n";

		cout << "custoemr arrivel time \t" << Times[0].hours << ":" << Times[0].minutes << "\n";
		cout << "custoemr serivce time \t" << Times[1].hours << ":" << Times[1].minutes << "\n";

		cout << "custoemr depatyre time \t" << Times[2].hours << ":" << Times[2].minutes << "\n";
		cout << "custoemr wait time time \t" << Times[3].hours << ":" << Times[3].minutes << "\n";

	}

};


int main() {
	linked_list tellers;
	details one;
	details two;
	details three;
	details four;
	details five;
	details six;

	queue q;
	

	//data ented in HH:mm 

		one.arrivel_time.hours = 7;
		one.arrivel_time.minutes = 5;
		one.service_time.minutes = 5;

		two.arrivel_time.hours = 7;
		two.arrivel_time.minutes = 2;
		two.service_time.minutes = 5;


		three.arrivel_time.hours = 7;
		three.arrivel_time.minutes = 10;
		three.service_time.minutes = 4;

		four.arrivel_time.hours =7;
		four.arrivel_time.minutes = 3;
		four.service_time.minutes = 5;


		five.arrivel_time.hours = 7;
		five.arrivel_time.minutes = 7;
		five.service_time.minutes = 3;

		six.arrivel_time.hours = 7;
		six.arrivel_time.minutes = 8;
		six.service_time.minutes = 5;


	

	//Reacommanded test  3 test total 

									/*customers test 1	
		
		
		q.enqueue(one);
		q.enqueue(two);
		q.enqueue(three);
		q.enqueue(four);
		q.enqueue(five);
		q.enqueue(six);
	*/
	

												/*TEST 2
customers arrive either in the same time with same  service time	or
 	customers arrive within minutes from  each other  with varrying  services time 120 customers
		for (int i = 0; i < 20; i++) {
			q.enqueue(one);
			q.enqueue(two);
		q.enqueue(three);
		q.enqueue(four);
		q.enqueue(five);
		q.enqueue(six);
		}
		

		*/
	

							/*TEST 3
	All customers arrive in the same time and have the same service time 100 customers  100% accuracy
		for (int i = 0; i < 100; i++) {
			q.enqueue(one);
		}
	*/
	
		
		/*dynmic data insertion*/

		int customersInBank;
		

		cout << "enter number of customes to simalute the queue";
		cin >> customersInBank;

		for (int i = 0; i < customersInBank; i++) {

			details d;
			cout << "entear Customer arrivel hour \t";
			cin >> d.arrivel_time.hours;
			cout << "\n";
			cout << "entear Customer arrivel miute \t";
			cin >> d.arrivel_time.minutes;
			cout << "\n";
			cout << "entear service time in miutes \t ";
			cin >> d.service_time.minutes;
			q.enqueue(d);


		}

	
	q.bublesort();
	
	
	tellers.add(1);
	tellers.add(2);
	tellers.add(3);
	tellers.head->name = "mostafa";
	tellers.head->next->name = "ahmed";
	tellers.head->next->next->name = "moataz";

cout << "\t\t\t Welcome to Mesh bank masr queue mangement system :D \n";

amountOfCustomersINBankcustomes =q.size();

 do{
		tellers.srvingsustomers(q);

	}	while (q.hea != NULL);



	cout <<"total cusotmers in the bank \t" << amountOfCustomersINBankcustomes <<"\n";
	cout << "service time elapsed in the bank\t" <<':' << TotalServiceTimeIntheBak.minutes<<"\t miutes" << "\n";


	cout << "teller utlization\t";
	tellers.customesrServedByeachTeller(amountOfCustomersINBankcustomes);
	
	
	if (waitTime.minutes > 0) {
	cout << "\n";
	cout << "total waittime in the bank \t "<< waitTime.minutes <<" miutes" << "\n";
	
	cout << " averge wait time in the bank \t " << waitTime.minutes/waitingcustomers  << "\n";
	}
	else
	{
		cout << " averge wait time in the bank " << 0;
	}

	return 0;
};










