


class Queue : private List {
	public:
		Queue();
		Queue(Queue& queue);
		void operator=(Queue& queue);
		int size() const;
		void Add(int elem);
		int Poll();
		bool IsEmpty() const;
};

