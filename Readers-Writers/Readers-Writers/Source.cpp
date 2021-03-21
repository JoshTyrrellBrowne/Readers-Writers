#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include <queue>


struct Database
{
	int health;
};

Database database;
std::mutex m_consumerMutex;
std::mutex m_producerMutex;

void Reader()
{

}

void Writer()
{

}

int main()
{
	/*std::thread producerThreadOne(producer);
	std::thread consumerThreadOne(consumer);
	std::thread producerThreadTwo(producer);
	std::thread consumerThreadTwo(consumer);
	std::thread producerThreadThree(producer);
	std::thread consumerThreadThree(consumer);
	producerThreadOne.join();
	consumerThreadOne.join();

	producerThreadTwo.join();
	consumerThreadTwo.join();

	producerThreadThree.join();
	consumerThreadThree.join();*/

	system("pause");
	return 0;
}