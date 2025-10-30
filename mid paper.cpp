#include <iostream>
using namespace std;


struct PatientNode {
    int id;
    PatientNode* previous;
    PatientNode* next;

    PatientNode(int Id) {
        id = Id;
        previous = NULL;
        next = NULL;
    }
};


class HospitalQU {
private:
    PatientNode* Front;
    PatientNode* Rear;

public:
    HospitalQU() {
        Front = NULL;
        Rear = NULL;
    }



  
    void addEnd(int patientId) {
        PatientNode* node = new PatientNode(patientId);

        if (Rear == NULL) {
            Front = Rear = node;
        } else {
            Rear->next = node;
            node->previous = Rear;
            Rear = node;
        }
    }
    
        void addFront(int patientId) {
        PatientNode* node = new PatientNode(patientId);

        if (Front == NULL) {
            Front = Rear = node;
        } else {
            node->next = Front;
            Front->previous = node;
            Front = node;
        }
    }


  
    void addPosition(int patientId, int position) {
        if (position <= 1 || Front == NULL) {
            addFront(patientId);
            return;
        }

        PatientNode* node = new PatientNode(patientId);
        PatientNode* temp = Front;
        int index = 1;

     
        while (temp->next != NULL && index < position - 1) {
            temp = temp->next;
            index++;
        }

  
        if (temp->next == NULL) {
            addEnd(patientId);
            return;
        }

        node->next = temp->next;
        node->previous = temp;
        temp->next->previous = node;
        temp->next = node;
    }

   
    void removeFront() {
        if (Front == NULL) {
            cout << "Que is empty. No to remove.\n";
            return;
        }

        PatientNode* temp = Front;

        if (Front == Rear) {
            Front = Rear = NULL;
        } else {
            Front = Front->next;
            Front->previous = NULL;
        }

        delete temp;
    }

 


    void showBackward() {
        cout << "Que Rear -> Front: ";
        PatientNode* temp = Rear;
        while (temp != NULL) {
            cout << temp->id << " <-> ";
            temp = temp->previous;
        }
        cout << "NULL\n";
    }
       void showForward() {
        cout << "Que Front -> Rear: ";
        PatientNode* temp = Front;
        while (temp != NULL) {
            cout << temp->id << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

 
    int frontID() const { return (Front ? Front->id : -1); }
    int rearID() const { return (Rear ? Rear->id : -1); }
};


int main() {
    HospitalQU que;

    que.addEnd(101);
    que.showForward();

  

    que.addFront(200);
    que.showForward();
    
    que.addEnd(102);
    que.showForward();
  
    que.removeFront();
    que.showForward();
    
    que.addPosition(150, 2);
    que.showForward();


    que.addEnd(300);
    que.showForward();

    cout << "\nFront patient ID IS : " << que.frontID();
    cout << "\nRear patientT ID: " << que.rearID() << endl;
}
