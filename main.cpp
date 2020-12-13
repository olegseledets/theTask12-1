#include <iostream>

int main() {
  std::string departureTime, arrivalTime;

  std::cout << "Введите время отправления: ";
  std::cin >> departureTime;
  if (departureTime.length() != 5 || departureTime[2] != ':' 
      || departureTime[0] < '0' || departureTime[0] > '9'
      || departureTime[1] < '0' || departureTime[1] > '9'
      || departureTime[3] < '0' || departureTime[3] > '9'
      || departureTime[4] < '0' || departureTime[4] > '9'){
        std::cout << "Ошибка ввода!\n";
  }
  else {
    std::cout << "Введите время прибытия: ";
    std::cin >> arrivalTime;
    if (arrivalTime.length() != 5 || arrivalTime[2] != ':' 
        || arrivalTime[0] < '0' || arrivalTime[0] > '9'
        || arrivalTime[1] < '0' || arrivalTime[1] > '9'
        || arrivalTime[3] < '0' || arrivalTime[3] > '9'
        || arrivalTime[4] < '0' || arrivalTime[4] > '9'){
          std::cout << "Ошибка ввода!\n";
    } 
    else{
      int dHours = 10 * (departureTime[0] - '0') + (departureTime[1] - '0');
      int dMinutes = 10 * (departureTime[3] - '0') + (departureTime[4] - '0');
      int aHours = 10 * (arrivalTime[0] - '0') + (arrivalTime[1] - '0');
      int aMinutes = 10 * (arrivalTime[3] - '0') + (arrivalTime[4] - '0');

      if (dHours > 23 || aHours > 23 || dMinutes > 59 || aMinutes > 59){
        std::cout << "Ошибка ввода! \n";
      }
      else{
        int dtMinutes = 60 * dHours + dMinutes;
        int atMinutes = 60 * aHours + aMinutes;
        if (dHours <= aHours){  
          int rTimes = atMinutes - dtMinutes;
          std::cout << "Поезд находится в пути " << rTimes / 60 << " часов " << rTimes % 60 << " минут\n";
        }
        else{
          int rTimes = (1440 - (dHours * 60) - dMinutes) + atMinutes;
          std::cout << "Поезд находится в пути " << rTimes / 60 << " часов " << rTimes % 60 << " минут\n";
        }
      }
    }
  } 
}

/*
1. Время в пути
Поезд отправляется в AA часов BB минут и прибывает в пункт назначения в CC часов DD минут. Сколько часов и минут он находится в пути?
Напишите программу, которая принимает от пользователя две строки — время отправления и время прибытия поезда. Время задается строкой из 5 символов в формате HH:MM. Обеспечьте контроль ввода, проверьте также, что время корректно.
Программа должна ответить, сколько часов и минут поезд находится в пути. Если время отправления больше времени прибытия, считайте, что поезд прибывает в пункт назначения на следующий день.
Примеры:
Введите время отправления: 07:15
Введите время прибытия: 16:55
Поезд находится в пути 9 часов 40 минут

Введите время отправления: 21:10
Введите время прибытия: 08:05
Поезд находится в пути 10 часов 55 минут
*/