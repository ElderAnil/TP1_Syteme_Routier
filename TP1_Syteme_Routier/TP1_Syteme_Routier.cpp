#include <iostream>
#include "Vehicle.h"
#include "VehicleQueue.h"

using namespace std;

int main()
{
    Vehicle v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20;
    //Vehicle v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40;

    //Vehicle v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40;



    v1.InitVehicle("V001", "Voiture", 0, "Nord");
    v2.InitVehicle("V002", "Camion", 0, "Nord");
    v3.InitVehicle("V003", "Moto", 0, "Nord");
    v4.InitVehicle("V004", "Voiture", 0, "Nord");
    v5.InitVehicle("V005", "Voiture", 0, "Nord");
    v6.InitVehicle("V006", "Voiture", 0, "Nord");
    v7.InitVehicle("V007", "Voiture", 0, "Nord");


    VehicleQueue file;
    std::cout << file.isEmpty();


    file.enqueueVehicle(v1);

    file.dequeueVehicle();

    file.enqueueVehicle(v2);
    file.enqueueVehicle(v3);
    file.enqueueVehicle(v4);
    file.enqueueVehicle(v5);
    file.enqueueVehicle(v6);
    file.enqueueVehicle(v7);
    file.enqueueVehicle(v8);
    file.enqueueVehicle(v9);

    file.peekVehicle();
    std::cout << file.isEmpty();
    std::cout << file.getNumberVehicle();
    file.displayVehicle();


    return 0;
}