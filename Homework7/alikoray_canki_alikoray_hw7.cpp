#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <random>
#include <time.h>
#include"alikoray_canki_alikoray_hw7_HW7DynIntQueue.h"

using namespace std;

HW7DynIntQueue filling_queue;
HW7DynIntQueue packing_queue;
mutex myMutex, coutMutex,packMutex;
int total_box_count; // global variables 
int counter=0;
int pack_counter=0;

/* Begin: code taken from incrementDecrement.cpp */
int random_range(const int & min, const int & max) {
    static mt19937 generator(time(0));
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}
/* End: code taken from incrementDecrement.cpp */

void producer (int a, int b) { // void function that is made for producing empty boxes in random time by producing_worker thread
for(int i = 0; i < total_box_count; i++)
	{
			
		time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); // takes current time
		struct tm *ptm = new struct tm; 
		localtime_s(ptm, &tt);
		int filling_time = random_range(a, b); // takes a random time from  function
		this_thread::sleep_for(chrono::seconds(filling_time)); // sleeps the thread in that random time
		tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
		localtime_s(ptm, &tt);

		myMutex.lock(); // a mutex locking the queue to prevent queing the boxes at the same time by mulitple threads
		filling_queue.enqueue(i);
		int getsize=filling_queue.getCurrentSize();
		myMutex.unlock(); // unlocking the queue

		coutMutex.lock(); // locking the mutex to prevent outputs' interleaved by another output of different thread
		cout <<"Producer has enqueued a new box "<< i+1 << " to filling queue (filling queue size is "<<getsize<< ") : "<<
		put_time(ptm,"%X") <<endl;
		coutMutex.unlock();
	}
}
void filler(int id,int a, int b ){ // a function takes empty boxes from queues, fill them and send it to packaging queue
int item;
while(counter<total_box_count){ // a loop continues untill counter = to total box count
	myMutex.lock(); // a mutex locking the queue to prevent queing the boxes at the same time by mulitple threads
	if (!filling_queue.isEmpty()) 
		{  
			filling_queue.dequeue(item); // takes empty boxes from queue
			counter++;

			//coutMutex.lock();
			time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
			struct tm *ptm = new struct tm; 
			localtime_s(ptm, &tt);

			int getsize=filling_queue.getCurrentSize();
			myMutex.unlock();

			coutMutex.lock(); // locking the mutex to prevent outputs' interleaved by another output of different thread
			cout <<"Filler "<< id <<" started filling the box "<<item+1<<" (filling queue size is "<<getsize<< ") : "<<
			put_time(ptm,"%X") <<endl;
			coutMutex.unlock(); // unlocks the cout mutex to make reusable from different threads again.

			int filling_time = random_range(a, b);
			this_thread::sleep_for(chrono::seconds(filling_time)); // simulation for consume
			tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
			localtime_s(ptm, &tt);

			coutMutex.lock();
			cout <<"Filler "<< id <<" finished filling the box "<<item+1<<": "<<put_time(ptm,"%X") <<endl;
			coutMutex.unlock();

			tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
			localtime_s(ptm, &tt);

			packMutex.lock();
			packing_queue.enqueue(item);
			int getsize2=packing_queue.getCurrentSize();
			packMutex.unlock();

			coutMutex.lock();
			cout <<"Filler "<< id<< " put box "<<item+1 <<" into packaging queue (packaging queue size is "<<getsize2<< ") : "<<
			put_time(ptm,"%X") <<endl;
			coutMutex.unlock();

		}
	else {
	myMutex.unlock();
	}

}
}

void package(int id, int a, int b){ // a void function takes filled boxes from the queue and starts to package them in random time 
int item;
while(pack_counter<total_box_count){ // a loop continues untill pack counter = total box count
	packMutex.lock();
	if (!packing_queue.isEmpty()) // if queue is not empty
		{  
			packing_queue.dequeue(item); // take item from the queue
			pack_counter++; // increment the pack counter
			//coutMutex.lock();
			time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
			struct tm *ptm = new struct tm; 
			localtime_s(ptm, &tt);
			int getsize=packing_queue.getCurrentSize();
			packMutex.unlock();

			coutMutex.lock();
			cout <<"Packager "<< id <<"  started packaging the box "<<item+1<<" (packaging queue size is "<<getsize<< ") : "<<
			put_time(ptm,"%X") <<endl;
			coutMutex.unlock();

			int filling_time = random_range(a, b);
			this_thread::sleep_for(chrono::seconds(filling_time)); // simulation for consume
			tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
			//ptm = new struct tm;
			localtime_s(ptm, &tt);

			coutMutex.lock();
			cout <<"Packager "<< id <<" finished packaging the box "<<item+1<<": "<<put_time(ptm,"%X") <<endl;
			coutMutex.unlock();


}
	else{
		packMutex.unlock();
	}

}
}

int main() {

int min_production,max_production,min_filling_time,max_filling_time,min_packaging_time,max_packaging_time;
cout<<"Please enter the total number of items:";
cin>>total_box_count;
cout<<"Please enter the min-max waiting time range of producer: "<<endl;
cout<<"Min: ";
cin>>min_production;
cout<<"Max: ";
cin>>max_production;
cout<<"Please enter the min-max waiting time range of filler workers: "<<endl;
cout<<"Min: ";
cin>>min_filling_time;
cout<<"Max: ";
cin>>max_filling_time;
cout<<"Please enter the min-max waiting time range of packager workers: "<<endl;
cout<<"Min: ";
cin>>min_packaging_time;
cout<<"Max: ";
cin>>max_packaging_time;
time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
struct tm *ptm = new struct tm; 
localtime_s(ptm, &tt);
cout<<"Simulation starts "<<put_time(ptm,"%X") <<endl;
thread producer_worker(&producer,min_production,max_production); // producer thread
thread filler_worker1(&filler,1,min_filling_time,max_filling_time); // filler thread1
thread filler_worker2(&filler,2,min_filling_time,max_filling_time); // filler thread2
thread packager_worker1(package,1,min_packaging_time,max_packaging_time); // packager thread1
thread packager_worker2(package,2,min_packaging_time,max_packaging_time); // packager thread2
producer_worker.join(); 
filler_worker1.join();
filler_worker2.join();
packager_worker1.join();
packager_worker2.join();
 tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
localtime_s(ptm, &tt);
cout<<"End of the simulation ends: "<<put_time(ptm,"%X") <<endl;


	return 0;
}