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
std::mutex mutex;
//std::mutex writerMutex;

int nr = 0; // num of readers currently accessing Database
int nw = 0; // num of writers currently accessing Database

void Reader(int t_readerID)
{
	while (nw != 0) {}   // wait until nw == 0		
	//we have access
	mutex.lock();
	nr = nr + 1; // increment reader count as this reader now has access
	std::cout << "Reader with ID: " << t_readerID << " is reading the database" << std::endl;
	std::cout << "Reading the Database, Health: " << database.health << std::endl;
	std::cout << std::endl;
	nr = nr - 1; // decrement reader count just as we finish reading
	mutex.unlock();
}

void Writer(int t_writerID)
{
	while (nr != 0 || nw != 0) {} // wait until both nw & nr == 0
	mutex.lock();
	nw = nw + 1; //increment writer count
	//write the database
	std::cout << "Writer with ID: " << t_writerID << " is changing the health of the boss" << std::endl;
	std::cout << "Health before change: " << database.health << std::endl;
	database.health -= 1; // decrement health
	std::cout << "Health after change: " << database.health << std::endl;
	std::cout << std::endl;
	nw = nw - 1; //decrement writer count
	mutex.unlock();
}

int main()
{
	database.health = 100; //intially 100

	std::thread readerThreadOne(Reader, 1);
	std::thread writerThreadOne(Writer, 1);
	std::thread readerThreadTwo(Reader, 2);
	std::thread writerThreadTwo(Writer, 2);
	std::thread readerThreadThree(Reader, 3);
	std::thread writerThreadThree(Writer, 3);
	readerThreadOne.join();
	writerThreadOne.join();

	readerThreadTwo.join();
	writerThreadTwo.join();

	readerThreadThree.join();
	writerThreadThree.join();

	system("pause");
	return 0;
}