/* Flight booking system part 1 
 *
 * System saves:
 * - identification number
 * - capacity
 * - number of seats reserverd
 *
 * TO DO:
 * - Print out a status report about the percentage of capacity filled:
 *    ex: "Flight[id] : [reserved]/[capacity] ([percentage]%) seats taken"
 */

#include <iostream>

class FligthBooking
{
public:
    FligthBooking(int id, int capacity, int reserved);
    void printStatus();
private:
    int id;
    int capacity;
    int reserved;
};

void FligthBooking::printStatus(void)
{
    std::cout << "Fligth " << id << " : " << reserved << "/" << capacity << " (" <<
        int(((float)reserved/capacity) * 100) << "%) seats taken" << std::endl;
}

FligthBooking::FligthBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
}

int main(void)
{
    int reserved = 0, capacity = 0;

    std::cout << "Provide fligth capacity: ";
    std::cin >> capacity;

    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;

    FligthBooking booking(1, capacity, reserved);

    booking.printStatus();

    return 0;
}
