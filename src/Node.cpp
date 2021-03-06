#include "Node.hpp"

Node::Node(int id) : m_id{id} { }

Node::Node(const Node &node) : m_id{node.m_id} {
    if (node.m_gen == nullptr) {
        m_gen = nullptr;
    } else {
        m_gen = node.m_gen;
    }
    kopiujDzieci(node);
}

Node::~Node() {
    for (Node* dziecko: m_dzieci) {
        delete dziecko;
    }
}

void Node::kopiujDzieci(const Node &stad) {
    for (Node *dziecko: stad.m_dzieci) {
        Node* nowy = dodajDziecko(dziecko->m_id);
        nowy->m_gen = dziecko->m_gen;
        nowy->kopiujDzieci(*dziecko);
    }
}

Node* Node::znajdzWezel(int id) {
    Node *szukany = nullptr;
    if (m_id == id) {
        return this;
    }

    for (Node* dziecko: m_dzieci) {
        szukany = dziecko->znajdzWezel(id);
        if (szukany != nullptr) {
            break;
        }
    }
    return szukany;
}

Node* Node::rodzicWezla(int id) {
    Node *szukany = nullptr;
    for (Node *dziecko: m_dzieci) {
        if (dziecko->m_id == id) {
            szukany = this;
            break;
        }
        szukany = dziecko->rodzicWezla(id);
    }
    return szukany;
}

Node* Node::dodajDziecko(int id) {
    Node *tmp = new Node(id);
    m_dzieci.push_back(tmp);
    return tmp;
}

int Node::id() {
    return m_id;
}

std::vector<Node*> Node::dzieci() {
    return m_dzieci;
}

int Node::rozmiarPoddrzewa() {
    int rozmiar = 0;
    for (auto dziecko: m_dzieci) {
        rozmiar += dziecko->rozmiarPoddrzewa();
    }
    return rozmiar + 1;
}

