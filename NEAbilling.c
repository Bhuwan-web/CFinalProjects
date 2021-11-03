#include<stdio.h>

// Custom data structure decellerations...............
struct bill
{
    int range;
    int minAmt;
    float rate;
};
// Function and Global constants declerations...............
int units(void);
float bill_processing(int,struct bill []);
const int SERVICE_CHARGE=125;
int MINIMUM_CHARGE=30;


//  Main Program...................................
int main(){

    int unit=units();
    int total_units=unit;
    struct bill point[]={
        {10,30,0},
        {10,30,3},
        {10,50,6.5},
        {20,50,8},
        {50,75,9.5},
        {50,100,9.5},
        {100,125,10},
        {150,150,11},
        {1000,175,12}
    };
    float energyCharge=bill_processing(unit,point);
    float billAmt=energyCharge+SERVICE_CHARGE;
    
    printf("\n\n\tDetail Information: \
    \n............................................... \
    \n\nUnit Consumed:\t%d \
    \nEnergy Charge:\t%.2f \
    \nService Charge:\t%d \
    \n......................... \
    \nTotal Charge: \t%.2f \
    \n\n\
    P.S: The data holds true only for the housold with Domestic(5A) Category\n"
    ,total_units,energyCharge,SERVICE_CHARGE,billAmt);
}


// get total units to bay bills for..................
int units(){
    int prevUnit,toadysUnit;
    printf("\
    \n\t------------------------------\
    \n\t| NEA Meter Reading Software |\
    \n\t------------------------------\
    \n\n Enter Following Datails: \
    \n \
    Previous Unit:");
    scanf("%d",&prevUnit);
    printf("\
    Present Unit: ");
    scanf("%d",&toadysUnit);
    return toadysUnit-prevUnit;
}


//  Standard NEA Bills payment methods for 5A households
float bill_processing(int units,struct bill point[9]){
    float billAmt;

    for(int i=0;units>0;i++){
        int range_unit;
        float range_rate;
        if(units>point[i].range){
            range_unit=point[i].range;
            units -=range_unit;
        }else{
            range_unit=units;
            units=0;
        }
        range_rate=point[i].rate;
        billAmt +=(float)range_unit*range_rate;
    }
    return billAmt+MINIMUM_CHARGE;
}