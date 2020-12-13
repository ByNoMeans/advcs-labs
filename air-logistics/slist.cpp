#include "slist.h"

slist::slist() {
    head_ = nullptr;
    tail_ = nullptr;
    length = 0;
}

slist::~slist() {
    clear();
}

void slist::add(Airport* add) noexcept {
    Node* n = new Node();
    n->data = add;
    n->next = nullptr;
    if (!head_) {
        head_ = n;
        tail_ = n;
    } else {
        tail_->next = n;
        tail_ = n;
    }
    length++;
}

void slist::clear() noexcept {
    for (Node* c=head_, *n; c; delete c->data, delete c, c=n) n = c->next;
    length = 0;
    head_ = nullptr;
    tail_ = nullptr;
}

bool slist::equals(const slist& in) const noexcept {
    if (in.size() != length) return false;
    Node* ic = in.head_;
    for (Node* c=head_; c; c=c->next, ic=ic->next) {
        Airport* c_d = c->data;
        Airport* in_d = ic->data;
        if (c_d->latitude_ !=in_d->latitude_ || c_d->longitude_!= in_d->longitude_ || strcmp(c_d->code_, in_d->code_) != 0)
            return false;
    }
    return ic == nullptr;
}

Node* slist::get(const int& index) const noexcept {
    assert(index < length && index > -1);
    Node* c = head_;
    for (int i=0; i < index; i++, c=c->next);
    return c;
}

void slist::insert(Airport* airport, const int& index) noexcept {
    assert(index > -1 && index < length);
    if (!index) {
        Node *c = new Node();
        c->data = airport;
        c->next = head_;
        head_ = c;
    } else if (index == length - 1) {
        add(airport);
    } else {
        Node *c = new Node();
        c->data = airport;
        Node* n = get(index - 1);
        c->next = n->next;
        n->next = c;
    }
    length++;
}

void slist::exchg(const int& index1, const int& index2) const noexcept {
    assert(index1 > -1 && index2 >-1 && index1 < length && index2 < length);
    if (index1 == index2) return;
    std::swap(get(index1)->data, get(index2)->data);
}

void slist::swap(const int& index1, const int& index2) noexcept {
    assert(index1 > -1 && index2 >-1 && index1 < length && index2 < length && index2 > index1);
    if (index1 == index2) return;
    if (index1) {
        Node* n1 = get(index1 - 1), *n2 = get(index2 - 1);
        std::swap(n1->next->next, n2->next->next);
        std::swap(n1->next, n2->next);
    } else {
        Node* n1 = get(index2 - 1);
        std::swap(head_->next, n1->next->next);
        std::swap(head_, n1->next);
    }
}

void slist::remove(const int& index) noexcept {
    assert(index < length && index > -1);
    if (!index) {
        Node *n = head_;
        head_ = head_->next;
        delete n;
    } else if (index == length - 1) {
        Node* p = get(index - 1);
        Node* l = p->next;
        tail_ = p;
        p->next = nullptr;
        delete l;
    } else {
        Node* p = get(index - 1);
        Node* l = p->next;
        p->next = p->next->next;
        delete l;
    }
    length--;
}

void slist::set(const int& index, Airport* airport) const noexcept {
    assert(index < length && index > -1);
    get(index)->data = airport;
}

int slist::size() const noexcept {
    return length;
}

slist* slist::subList(const int& start, const int& size) const noexcept {
    assert(start < length && start + size < length);
    auto* out = new slist();
    int i = 0;
    for (Node* c=head_; i<start+size; i++, c=c->next)
        if (i >= start)
            out->add(c->data);
    return out;
}

void slist::toString() const noexcept {
    int i = 0;
    for (Node* c=head_; c; c->data->print(), c=c->next, i++)
        std::cout << std::to_string(i) + ": ";
}
