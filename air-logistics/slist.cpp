#include "slist.h"

slist::slist() {
    head_ = nullptr;
    tail_ = nullptr;
    length = 0;
}

slist::~slist() {
    for (Node* c = head_, *n; c != nullptr; c = n) {
        n = c->next;
        delete c->data;
        delete c;
    }
}

void slist::add(Airport& add) {
    Node* n = new Node();
    n->data = &add;
    n->next = nullptr;
    if (head_ == nullptr) {
        head_ = n;
        tail_ = n;
    } else {
        tail_->next = n;
        tail_ = tail_->next;
    }
    length++;
}

void slist::clear() {
    for (Node* c=head_, *n; c != nullptr; c = n) {
        n = c->next;
        delete c->data;
        delete c;
    }
    length = 0;
}

bool slist::equals(const slist& in) const {
    if (in.size() != length) return false;
    Node* ic = in.head_;
    for (Node* c=head_; c != nullptr; c=c->next, ic=ic->next) {
        Airport* c_d = c->data;
        Airport* in_d = ic->data;
        if (c_d->latitude_ !=in_d->latitude_ || c_d->longitude_!= in_d->longitude_ || strcmp(c_d->code_, in_d->code_) != 0)
            return false;
    }
    return ic == nullptr;
}

Node* slist::get(const int& index) const {
    assert(index < length && index > -1);
    Node* c = head_;
    for (int i=0; i <= index; i++, c=c->next);
    return c;
}

void slist::insert(Airport& airport, const int& index) {
    assert(index > -1 && index < length);
    Node* c = new Node();
    if (index == 0) {
        c->data = &airport;
        c->next = head_;
        head_ = c;
    } else {
        c->data = &airport;
        Node* n = get(index);
        c->next = n->next;
        n->next = c;
    }
    length++;
}

void slist::exchg(const int& index1, const int& index2)  {
    assert(index1 > -1 && index2 >-1 && index1 < length && index2 < length);
    if (index1 == index2) return;
    std::swap(get(index1)->data, get(index2)->data);
}

void slist::swap(const int& index1, const int& index2) {
    assert(index1 > -1 && index2 >-1 && index1 < length && index2 < length);
    if (index1 == index2) return;
    Node* n1; Node* n1_p;
    Node* n2; Node* n2_p;
    if (index1 == 0) {
        n1_p = head_;
        n1 = n1_p->next;
    } else {
        n1_p = get(index1 -1);
        n1 = n1_p->next;
    }
    if (index2 == 0) {
        n2_p = head_;
        n2 = n2_p->next;
    } else {
        n2_p = get(index2 -1);
        n2 = n2_p->next;
    }
    std::swap(n1->data, n2->data);
    std::swap(n1->next, n2->next);
    n1_p->next = n2;
    n2_p->next = n1;
}

bool slist::isEmpty() const {
    return length == 0;
}

void slist::remove(const int& index) {
    assert(index < length && index > -1);
    if (index == 0) {
        head_->next = head_->next->next;
        delete head_->next;
    } else {
        Node* n = get(index - 1);
        n->next = n->next->next;
        delete n->next;
    }
    length--;
}

void slist::set(const int& index, Airport& airport) {
    assert(index < length && index > -1);
    get(index)->data = &airport;
}

int slist::size() const {
    return length;
}

slist slist::subList(const int& start, const int& size) const {
    assert(start < length && start + size < length);
    slist out;
    int i = 0;
    for (Node* c=head_; i<start+size; i++, c=c->next)
        if (i >= start)
            out.add(*(c->data));
    return out;
}

std::string slist::toString() const {
    int i = 0;
    std::string out;
    for (Node* c=head_; c!=nullptr; c=c->next)
        out += std::to_string(i) + ": " + c->data->code_ + ":  ("
                + std::to_string(c->data->longitude_) + ", "
                + std::to_string(c->data->latitude_) + ") Distance from AUS: "
                + std::to_string(c->data->distance_au_) + " miles\n";
    return out;
}