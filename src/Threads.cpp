#include <iostream>
#include <thread>

// Basically threads are the ability to execute parts of your program in another core of the computer, to allow parallelized computing
// First import the thread headers, then create the function you want to execute in parallel, then create a thread with `std::thread threadWorkerName(FunctionToExecuteInNewThread);`
// When you want to "Close" the thread, just execute threadWorkerName.join(), which will execute the function the thread has until the end, before safely closing it
// Inside the function being executed in the worker thread we call `std::this_thread::sleep_for(seconds)` to guarantee that or thread execute things every 1 second. This is very immportant, because without it our thread will try to execute as fast as possible, which can result in the processor getting to 100% without it being really necessary

static bool s_Finished = false;

void DoWork()
{
    using namespace std::literals::chrono_literals;

    std::cout << "Started thread with id: " << std::this_thread::get_id() << std::endl;

    int count = 0;
    while (!s_Finished)
    {
        std::cout << "Working... [" << count << "]" << std::endl;
        count++;

        std::this_thread::sleep_for(1s);
    }
}

void ExecuteThreads()
{
    std::cout << "Started program in thread with id: " << std::this_thread::get_id() << std::endl;
    std::thread worker(DoWork);

    std::cin.get();
    s_Finished = true;
    
    worker.join();
    std::cout << "Finished" << std::endl;
}
