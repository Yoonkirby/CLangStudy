#include <iostream>
using namespace std;

class Car
{
    private:
        int gasolineGauge;
    public:
        Car(int gasoline)
            :gasolineGauge(gasoline)
        { }
        int GetGasGauge()
        {
            return gasolineGauge;
        }
};

class HybridCar :public Car    //하이브리드 자동차
{
    private:
        int electricGauge;
    public:
        HybridCar(int gasoline, int electric)
            :Car(gasoline), electricGauge(electric)
        { }
        int GetElecGauge()
        {
            return electricGauge;
        }
};

class HybirdWaterCar :public HybridCar //하이브리드 워터카
{
    private:
        int waterGauge;
    public:
        HybirdWaterCar(int gasoline, int electric, int water)
            :HybridCar(gasoline,electric), waterGauge(water)
        { }
        void ShowCurrentGauge()
        {
            cout<<"remain Gasoline : "<<GetGasGauge()<<endl;
            cout<<"remain Electric : "<<GetElecGauge()<<endl;
            cout<<"remain Water : "<<waterGauge<<endl;
        }
};

int main(void)
{
    HybirdWaterCar mycar(100,200,300);
    mycar.ShowCurrentGauge();
    return 0;
}