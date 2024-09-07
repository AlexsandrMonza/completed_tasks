#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx_read_vec;
mutex mtx_delivery;

vector<int> orderList;

int delivery_count=0;

string name [5]={"Pizza","Soup","Steak","Salad","Sushi"};

void ready (int in_eat) {
    this_thread::sleep_for (chrono::seconds (rand()%6+10));
    cout << "Ready: " << name[in_eat] << "\n";

    mtx_read_vec.lock ();
    orderList.push_back (in_eat);
    mtx_read_vec.unlock ();
}


void delivery () {
    while(true) {
        this_thread::sleep_for (chrono::seconds (30));
        for (int i = 0; i < orderList.size (); i++) {
            cout << "Delivery: " << name[orderList[i]] << "\n";
        }

        mtx_read_vec.lock ();
        orderList.clear ();
        mtx_read_vec.unlock ();

        mtx_delivery.lock();
        delivery_count+=1;
        mtx_delivery.unlock();

        if(delivery_count==10){
            break;
        }
    }
}

int main () {
    srand (time(NULL));

    thread Delivery (delivery);

    while(true) {
        this_thread::sleep_for(chrono::seconds(rand()%6+5));
        int eat=rand()%5;
        cout<<"Order: "<<name[eat]<<"\n";
        thread Ready (ready,eat);
        Ready.detach();

        if(delivery_count==10){
            break;
        }
    }
    Delivery.join ();
}