#include "ofApp.h"
#include <cstdlib>

//--------------------------------------------------------------
void ofApp::setup() {
    llist = new SinglyLinkedList();
}

//--------------------------------------------------------------
void ofApp::update() {
    positionX += ofGetLastFrameTime() * 10;
    positionY = sin(positionX) * amplitude + 350;
}

//--------------------------------------------------------------
void ofApp::draw() {
    SinglyLinkedListNode* temp = llist->head;
    int i = 0;
    float prevPosX = -1;
    float prevPosY = positionY;

    while (temp != nullptr) {
        float posX = positionX + i * 200;

        float waveOffset = sin(ofGetElapsedTimef() + i * 0.2) * 50;  // Adjust amplitude & frequency
        float posY = positionY + waveOffset;

        if (prevPosX != -1) {
            ofSetColor(255, 0, 0);  // Red line
            ofDrawLine(prevPosX, prevPosY, posX, posY);
        }

        ofSetColor(0);  // Black circle
        ofDrawCircle(posX, posY, temp->data);  // Fixed radius

        ofSetColor(255);  // White text
        ofDrawBitmapString(std::to_string(temp->data), posX - 10, posY + 5);

        // Store current position as previous for the next iteration
        prevPosX = posX;
        prevPosY = posY;

        temp = temp->next;
        i++;
    }

}
void ofApp::augmenterAmplitude() {
    amplitude = amplitude + 10;
}

void ofApp::diminuerAmplitude() {
    amplitude = amplitude - 10;
}

void ofApp::bougerGauche() {
    positionX -= 20;
}

void ofApp::bougerDroite() {
    positionX += 20;
}

void ofApp::trierCroissant() {

}



//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 'q' || key == 'Q') {
        data = rand() % 100;
        llist->insertNodeAtHead(data);
    }
    if (key == 'w' || key == 'W') {
        data = rand() % 100;
        llist->insertNodeAtTail(data);
    }
    if (key == 'a' || key == 'A') {
        position = 0;
        if (llist->size > 0) {
            llist->deleteNode(position);
        }
    }
    if (key == 's' || key == 'S') {
        position = llist->size - 1;
        if (llist->size > 0) {
            llist->deleteNode(position);
        }
    }
    if (key == 'z' || key == 'Z') {
        augmenterAmplitude();
    }
    if (key == 'x' || key == 'X') {
        diminuerAmplitude();
    }
    if (key == OF_KEY_LEFT) {
        bougerGauche();
    }
    if (key == OF_KEY_RIGHT) {
        bougerDroite();
    }
    if (key == 'e' || key == 'E') {
        llist->sortAscending();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void SinglyLinkedList::insertNodeAtHead(int data) {
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    temp->next = head;
    head = temp;
    size++;
}

void SinglyLinkedList::insertNodeAtTail(int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    if (!head) {
        head = newNode;
        size++;
        return;
    }

    SinglyLinkedListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

void SinglyLinkedList::deleteNode(int position) {
    if (!head || position < 0 || position >= size) return;

    SinglyLinkedListNode* temp = head;

    if (position == 0) {
        head = head->next;
        delete temp;
        size--;
        return;
    }

    SinglyLinkedListNode* prev = nullptr;
    for (int i = 0; temp != nullptr && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return;

    prev->next = temp->next;
    delete temp;
    size--;
}

void SinglyLinkedList::sortAscending() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        SinglyLinkedListNode* current = head;
        SinglyLinkedListNode* prev = nullptr;

        while (current && current->next) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);
}






