#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using std::vector;
using std::queue;


struct Request {

	Request(int arrival_time, int process_time):
		arrival_time(arrival_time),
		process_time(process_time)
	{}

	int arrival_time;
	int process_time;
};


struct Response {
	Response(bool dropped, int start_time):
		dropped(dropped),
		start_time(start_time)
	{}

	bool dropped;
	int start_time;
};


class Buffer {
public:

	Buffer(int size):
		size_(size),
		finish_time_()
	{}

	Response Process(const Request &request) {
		while(!finish_time_.empty() && finish_time_.front() <= request.arrival_time) {

		    finish_time_.pop_front();
		}

		bool dropped = ((this->finish_time_.size() == this->size_) && (request.arrival_time < this->finish_time_.back()));

		int start_time = -1;

		if (!dropped) {

			if (finish_time_.empty())
				start_time = request.arrival_time;

			else
				start_time = max(finish_time_.back(), request.arrival_time);

			finish_time_.push_back(start_time + request.process_time);

		}

		return Response(dropped, start_time);

	}

private:

	int size_;
	deque <int> finish_time_;

};

vector <Request> ReadRequests() {

	vector <Request> requests;

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i) {

		int arrival_time, process_time;

		cin >> arrival_time >> process_time;

		requests.push_back(Request(arrival_time, process_time));

	}

	return requests;
}


vector <Response> ProcessRequests(const vector <Request> &requests, Buffer *buffer) {

	vector <Response> responses;

	for (int i = 0; i < requests.size(); ++i)
		responses.push_back(buffer->Process(requests[i]));

	return responses;

}

void PrintResponses(const std::vector <Response> &responses) {

	for (int i = 0; i < responses.size(); ++i)
		cout << (responses[i].dropped ? -1 : responses[i].start_time) << endl;

}

int main() {

	int size;
	cin >> size;

	vector <Request> requests = ReadRequests();

	Buffer buffer(size);

	vector <Response> responses = ProcessRequests(requests, &buffer);

	PrintResponses(responses);

	return 0;
}