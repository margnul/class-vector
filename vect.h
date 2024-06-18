#pragma once

template <typename ClassDataType>
class vect {
private:
	struct element {
		struct element *next_element;
		ClassDataType content;
	};

	struct element* begin = NULL;
	struct element* end = NULL;

	bool search_end(){
		if (begin == end) return false;
		struct element* current_element = begin;
		while (current_element->next_element->next_element != NULL) {
			current_element = current_element->next_element;
		}
		end = current_element;
		return true;
	}

public:

	/// инициализация
		// пустой вектор
	vect() {
		begin = NULL;
		end = NULL;
	}

		// конструктор копии
	vect(const vect& v) {
		if (v.begin == NULL) return;
		struct element* iterator = v.begin;
		begin = new struct element { NULL, iterator->content };
		struct element* current_element = begin;
		while (iterator->next_element != NULL) {
			iterator = iterator->next_element;
			current_element->next_element = new struct element { NULL, iterator->content };
			current_element = current_element->next_element;
		}
		end = current_element;
	}

		// вектор по количеству одинаковых элементов
	vect(int quantity, ClassDataType value) {	
		if (quantity == 0) return;
		begin = new struct element { NULL, value };
		struct element* current_element = begin;
		for (int i = 0; i < quantity - 1; i++) {
			current_element->next_element = new struct element { NULL, value };
			current_element = current_element->next_element;
		}
		end = current_element;
	}	


		// вектор по массиву
	vect(int length, ClassDataType array_[]) {
		begin = new struct element { NULL, array_[0] };
		struct element* current_element = begin;
		for (int i = 1; i < length; i++) {
			current_element->next_element = new struct element { NULL, array_[i]};
			current_element = current_element->next_element;
		}
		end = current_element;
	}


	/// операторы
	friend void operator+=(vect &a, vect &b) {
		a.end->next_element = b.begin;
		a.end = b.end;
	}

	friend bool operator==(vect a, vect b) {
		struct element* iterator_a = a.begin;
		struct element* iterator_b = b.begin;
		while (iterator_a != NULL && iterator_b != NULL) {
			if (iterator_a->content != iterator_b->content) return false;
			iterator_a = iterator_a->next_element;
			iterator_b = iterator_b->next_element;
		}
		if (iterator_a != NULL || iterator_b != NULL) return false;
		return true;
	}


	/// действия
	ClassDataType push_back(ClassDataType value) {
		end->next_element = new struct element {NULL, value};
		end = end->next_element;
		return value;
	}

	ClassDataType pop_back() {
		if (begin == NULL) return NULL;
		if (search_end()) {
			ClassDataType save = end->next_element->content;
			delete end->next_element;
			end->next_element = NULL;
			return save;
		}
		else {
			ClassDataType save = begin->content;
			delete begin;
			begin = NULL;
			end = NULL;
		}
	}

	void print() {
		struct element* current_element = begin;
		while (current_element->next_element != NULL) {
			printf("%d ", current_element->content);
			current_element = current_element->next_element;
		}
		printf("%d ", current_element->content);
	}
	
};