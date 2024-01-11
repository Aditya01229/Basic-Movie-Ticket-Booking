#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class movieTicket
{
public:
    int movieNum;
    int slotNum;
    int row;
    int column;

    void setTicket(int a, int b, int c, int d)
    {
        movieNum = a - 1;
        slotNum = b - 1;
        row = c - 1;
        column = d - 1;
    }
};

class User
{
public:
    string userName;
    int id;
    static int count;
    vector<movieTicket> ticket;

    User()
    {
        while ((getchar()) != '\n')
            ;
        cout << "Enter your Name: ";
        cin >> userName;
        count++;
        id = count;
        cout << "Registered Successfully!\nYour ID is " << id << " !\nNow you can proceed to booking!" << endl
             << endl;
    }
};

class theatre
{
public:
    int seats[7][7];
    string timeSlot;
    void notSeats();
    void displaySeats();
    theatre()
    {
        cout << "Enter the time of slot: ";
        cin >> timeSlot;
    }
};

class Movies
{
public:
    string movieName;
    int numberOfSlots;
    vector<theatre> slots;

    Movies()
    {
        cout << "Name of Movie:";
        while ((getchar()) != '\n')
            ;
        getline(cin, movieName);
        cout << "Number of slots:";
        cin >> numberOfSlots;
        cin.ignore();
        slots.resize(numberOfSlots);
        for (int i = 0; i < numberOfSlots; i++)
        {
            slots[i].notSeats();
        }
        cout << endl;
    }
    void displayTimeSlots();
};
void movieNameDisplay(vector<Movies> &v);

int main(int argc, char const *argv[])
{

    int numberOfMovies;
    vector<Movies> objectOfMovies;
    vector<User> userObjects;
    bool runStatus = 1;
    while (runStatus)
    {
        cout << "1. Admin\n2. User\n3. Exit\nInput: ";
        int person;
        cin >> person;
        cout << endl;
        if (person == 1)
        {
            cout << "1. Register Movie and It's Slots.\n2. Make changes in Scheduled Movies.\n3. Display Movies and Time Slots\nInput: ";
            int choice;
            cin >> choice;
            cout << endl;
            if (choice == 1)
            {
                cout << "Enter number of movies:";
                cin >> numberOfMovies;
                cout << endl;
                objectOfMovies.resize(objectOfMovies.size() + numberOfMovies);
                cout << "Registeration Done" << endl
                     << endl;
            }
            else if (choice == 2)
            {
                if (objectOfMovies.size() > 0)
                {

                    cout << "1. Make changes in Movie.\n2. Make changes in time slots.\nInput: ";
                    cin >> choice;
                    cout << endl;
                    if (choice == 1)
                    {
                        movieNameDisplay(objectOfMovies);

                        cout << "Select the movie you want to change: ";
                        cout << endl;
                        int movieChoice;
                        cin >> movieChoice;
                        cout << "1. Change the Name of Movie.\n2. Delete the Movie and it's Data.\nInput: ";
                        int task;
                        cin >> task;
                        cout << endl;
                        if (task == 1)
                        {
                            cout << "Enter the correct Name of the Movie: ";
                            while ((getchar()) != '\n')
                                ;
                            cin >> objectOfMovies[movieChoice - 1].movieName;
                        }
                        else if (task == 2)
                        {
                            objectOfMovies.erase(objectOfMovies.begin() + (movieChoice - 1));
                            cout << "Deleted Successfully!" << endl
                                 << endl;
                        }
                        else
                        {
                            cout << "Select a valid response." << endl
                                 << endl;
                        }
                    }
                    else if (choice == 2)
                    {
                        movieNameDisplay(objectOfMovies);
                        cout << "Select the movie you want to change: ";
                        int movieChoice;
                        cin >> movieChoice;
                        objectOfMovies[movieChoice - 1].displayTimeSlots();
                        cout << "Select the time slot you want to change: ";
                        int timeChoice;
                        cin >> timeChoice;
                        cout << "Enter the new time slot: ";
                        cin >> objectOfMovies[movieChoice - 1].slots[timeChoice - 1].timeSlot;
                        cout << "Changed Successfully." << endl
                             << endl;
                    }
                    else
                    {
                        cout << "Select a valid response." << endl
                             << endl;
                    }
                }
                else
                {
                    cout << "Register Movies First." << endl
                         << endl;
                }
            }

            else if (choice == 3)
            {
                movieNameDisplay(objectOfMovies);
                if (objectOfMovies.size() > 0)
                {
                    cout << "Select the movie to view it's time slot.";
                    int movieChoice;
                    cin >> movieChoice;
                    cout << endl;
                    objectOfMovies[movieChoice - 1].displayTimeSlots();
                }
            }
            else
            {
                cout << "Select a valid response." << endl
                     << endl;
            }
        }
        else if (person == 2)
        {
            cout << "New to Movie Booking System?\n1. Register!\n2. Book a Ticket!\n3. View your Bookings\n4. Cancel your Ticket\nInput: ";
            int choice;
            cin >> choice;
            cout << endl;
            if (choice == 1)
            {
                userObjects.resize(userObjects.size() + 1);
            }
            else if (choice == 2)
            {
                cout << "Enter your ID: ";
                int idOfUser;
                cin >> idOfUser;
                cout << endl;
                if (idOfUser <= User::count)
                {
                    movieNameDisplay(objectOfMovies);
                    cout << "Select the Movie you want to Book: ";
                    int movieChoice;
                    cin >> movieChoice;
                    objectOfMovies[movieChoice - 1].displayTimeSlots();
                    cout << "Select the Time Slot: ";
                    int slotUser;
                    cin >> slotUser;
                    cout << endl;
                    objectOfMovies[movieChoice - 1].slots[slotUser - 1].displaySeats();
                    cout << endl;
                    cout << "Enter the row and column of the seat you want to book: ";
                    int row, column;
                    cin >> row >> column;
                    if (row == 4 || (column == 4 && row > 1) || row > 7 || column > 7)
                    {
                        cout << "Invalid Seat! Type the correct row and column!" << endl
                             << endl;
                    }
                    else if (objectOfMovies[movieChoice - 1].slots[slotUser - 1].seats[row - 1][column - 1] == 1)
                    {
                        cout << "Seat is already Booked!\nBook Another Ticket." << endl
                             << endl;
                    }
                    else
                    {
                        objectOfMovies[movieChoice - 1].slots[slotUser - 1].seats[row - 1][column - 1] = 1;
                        userObjects[idOfUser - 1].ticket.resize(userObjects[idOfUser - 1].ticket.size() + 1);
                        userObjects[idOfUser - 1].ticket[userObjects[idOfUser - 1].ticket.size() - 1].setTicket(movieChoice, slotUser, row, column);
                        cout << "Movie Booked Succesfully!" << endl
                             << endl;
                    }
                }

                else
                {
                    cout << "User not found" << endl
                         << endl;
                }
            }
            else if (choice == 3)
            {
                cout << "Enter your ID: ";
                int idOfUser;
                cin >> idOfUser;
                cout << endl;
                if (idOfUser <= User::count)
                {
                    if (userObjects[idOfUser - 1].ticket.size() == 0)
                    {
                        cout << "No Booking!" << endl
                             << endl;
                    }
                    for (int i = 0; i < userObjects[idOfUser - 1].ticket.size(); i++)
                    {
                        int a = userObjects[idOfUser - 1].ticket[i].movieNum;
                        int b = userObjects[idOfUser - 1].ticket[i].slotNum;
                        int c = userObjects[idOfUser - 1].ticket[i].row;
                        int d = userObjects[idOfUser - 1].ticket[i].column;
                        cout << "---------------------------------------------------" << endl;
                        cout << "Ticket " << i + 1 << endl;
                        cout << "Movie Name: " << objectOfMovies[a].movieName << "  |  Slot Time: " << objectOfMovies[a].slots[b].timeSlot << endl;
                        cout << "Row Number: " << c + 1 << endl
                             << "Column Number: " << d + 1 << endl;
                        cout << "---------------------------------------------------" << endl
                             << endl;
                    }
                }
                else
                {
                    cout << "User not Found" << endl
                         << endl;
                }
            }
            else if (choice == 4)
            {
                cout << "Enter your ID: ";
                int idOfUser;
                cin >> idOfUser;
                cout << endl;
                if (idOfUser <= User::count)
                {
                    if (userObjects[idOfUser - 1].ticket.size() == 0)
                    {
                        cout << "No Booking!" << endl
                             << endl;
                    }
                    for (int i = 0; i < userObjects[idOfUser - 1].ticket.size(); i++)
                    {
                        int a = userObjects[idOfUser - 1].ticket[i].movieNum;
                        int b = userObjects[idOfUser - 1].ticket[i].slotNum;
                        int c = userObjects[idOfUser - 1].ticket[i].row;
                        int d = userObjects[idOfUser - 1].ticket[i].column;
                        cout << "---------------------------------------------------" << endl;
                        cout << "Ticket " << i + 1 << endl;
                        cout << "Movie Name: " << objectOfMovies[a].movieName << "  |  Slot Time: " << objectOfMovies[a].slots[b].timeSlot << endl;
                        cout << "Row Number: " << c + 1 << endl
                             << "Column Number: " << d + 1 << endl;
                        cout << "---------------------------------------------------" << endl
                             << endl;
                    }

                    cout << "Enter the ticket number you want to cancel: ";
                    int cancel;
                    cin >> cancel;
                    cout << endl;
                    int a = userObjects[idOfUser - 1].ticket[cancel - 1].movieNum;
                    int b = userObjects[idOfUser - 1].ticket[cancel - 1].slotNum;
                    int c = userObjects[idOfUser - 1].ticket[cancel - 1].row;
                    int d = userObjects[idOfUser - 1].ticket[cancel - 1].column;
                    objectOfMovies[a].slots[b].seats[c][d] = 0;
                    userObjects[idOfUser - 1].ticket.erase(userObjects[idOfUser - 1].ticket.begin() + (cancel - 1));
                    cout << "Ticket Cancelled successfully!" << endl
                         << endl;
                }
                else
                {
                    cout << "User not found" << endl
                         << endl;
                }
            }
            else
            {
                cout << "Select a valid response." << endl
                     << endl;
            }
        }
        else if (person == 3)
        {
            runStatus = 0;
        }

        else
        {
            cout << "Select a Valid response." << endl
                 << endl;
        }
    }

    return 0;
}

int User::count = 0;

// Function to Display Movie Names
void movieNameDisplay(vector<Movies> &v)
{
    if (v.size() == 0)
    {
        cout << "No movie streaming currently." << endl
             << endl;
    }
    else
    {
        cout << "The movies currently streaming at theatre are:" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << i + 1 << ". " << v[i].movieName << endl;
        }
        cout << "----------------------------------------------" << endl;
        cout << endl;
    }
}

// Function to initialize the seats in the theatre.
void theatre::notSeats()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i == 3 || j == 3)
            {
                seats[i][j] = -1;
            }
            else
            {
                seats[i][j] = 0;
            }
        }
    }
    seats[0][3] = 0;
}

// Function to Display Seats.
void theatre::displaySeats()
{
    cout << "   1  2  3  4  5  6  7  " << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << "| ";
        for (int j = 0; j < 7; j++)
        {
            if (seats[i][j] == 0)
            {
                cout << "O  ";
            }
            else if (seats[i][j] == 1)
            {
                cout << "X  ";
            }
            else if (seats[i][j] == -1)
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
    cout << "______________________" << endl;
    cout << "   SCREEN THIS SIDE   " << endl;
}

// Function to Display Time Slots of a movie.
void Movies::displayTimeSlots()
{
    cout << "     TIME SLOTS      " << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < numberOfSlots; i++)
    {
        cout << i + 1 << " --> " << slots[i].timeSlot << endl;
    }
    cout << "---------------------" << endl;
    cout << endl;
}