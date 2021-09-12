#include <iostream>
#include <vector>

using namespace std;

#define INPUT(array) \
for(int i=0; i<sizeof(array)/sizeof(int); ++i){ \
    cout << "Enter quantity of passenger in the car " << i+1 << endl;\
    cin>>array[i];\
}

#define SUMELEMENTS(array, sum) \
for(int i=0; i<sizeof(array)/sizeof(int); ++i){ \
    sum+=array[i]; \
}

#define EMPTYWAGONS(array, predicat) {\
vector<int> empty_wagons;\
for(size_t i=0; i<sizeof(array)/sizeof(int); ++i){ \
    if(predicat(i)){\
        empty_wagons.push_back(i+1); \
    }\
}                                    \
if(!empty_wagons.empty())cout << "There are free seats in cars: ";\
for(const auto& i:empty_wagons){cout << i << ' ';} \
cout<<endl;                          \
}

#define CROWDEDWAGONS(array, predicat) {\
vector<int> crowded_wagons;\
for(size_t i=0; i<sizeof(array)/sizeof(int); ++i){ \
    if(predicat(i))crowded_wagons.push_back(i+1);\
}                                      \
if(!crowded_wagons.empty())cout<<"Cars are crowded: "; \
for(const auto& i:crowded_wagons) {cout<<i<<' ';}  \
cout<<endl;                            \
}

class Train {
public:
    Train() {
        INPUT(wagons);
    }

    bool EmptyWagons(size_t i) {
        return wagons[i] < 20;
    }

    bool CrowdedWagon(size_t i) {
        return wagons[i] > 20;
    }

    int wagons[10];
};

int main() {
    Train train;
    EMPTYWAGONS(train.wagons, train.EmptyWagons);
    CROWDEDWAGONS(train.wagons, train.CrowdedWagon);
    size_t quantity_of_passengers=0;
    SUMELEMENTS(train.wagons, quantity_of_passengers);
    cout<<"Total quantity of passengers: "<<quantity_of_passengers;
    return 0;
}
