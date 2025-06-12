#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

#include "C:\Programming\Libraries\clients_data.h"
using namespace clients_data;
#include "C:\Programming\Libraries\global_funcs.h"
using namespace global_funcs;

#include "C:\Programming\Libraries\funcs.h"

enum enScreen
{
    ClientsList = 1,
    AddNewClient = 2,
    DeleteClient = 3,
    UpdateClient = 4,
    FindClient = 5,
    Transactions = 6,
    ManageUsers = 7,
    Logout = 8
};

enum enTransaction
{
    Deposit = 1,
    Withdraw = 2,
    TotalBalances = 3,
    ExitTransactions = 4
};

enum enManageUsers
{
    UsersList = 1,
    AddNewUser = 2,
    DeleteUser = 3,
    UpdateUser = 4,
    FindUser = 5,
    ExitManageUsers = 6
};

/// /// /// ///

void showMainMenuScreen()
{
    cout << "==============================\n";
    cout << "      Main Menu Screen\n";
    cout << "==============================\n";
    cout << "  [1] Show Clients List\n";
    cout << "  [2] Add New Client\n";
    cout << "  [3] Delete Client\n";
    cout << "  [4] Update Client Info\n";
    cout << "  [5] Find Client\n";
    cout << "  [6] Transactions\n";
    cout << "  [7] Manage Users\n";
    cout << "  [8] Logout\n";
    cout << "==============================\n";
}

void resetScreen()
{
    system("cls");
}

void showScreenBottom()
{
    cout << "Press any key to go back to main menu...";
    system("Pause>0");
}

void showScreenHeader(enScreen screen)
{
    switch (screen)
    {
    case enScreen::ClientsList:
        cout << " ===============================================\n";
        cout << "\t\tClients List Screen\n";
        cout << " ===============================================\n";
        return;
    case enScreen::AddNewClient:
        cout << " ===============================================\n";
        cout << "\t\tAdd New Client Screen\n";
        cout << " ===============================================\n";
        return;
    case enScreen::DeleteClient:
        cout << " ===============================================\n";
        cout << "\t\tDelete Client Screen\n";
        cout << " ===============================================\n";
        return;
    case enScreen::UpdateClient:
        cout << " ===============================================\n";
        cout << "\t\tUpdate Client Screen\n";
        cout << " ===============================================\n";
        return;
    case enScreen::FindClient:
        cout << " ===============================================\n";
        cout << "\t\tFind Client Screen\n";
        cout << " ===============================================\n";
        return;
    case enScreen::Transactions:
        cout << "==============================\n";
        cout << "  Transactions Menu Screen\n";
        cout << "==============================\n";
        return;
    case enScreen::ManageUsers:
        cout << "==============================\n";
        cout << "   Manage Users Menu Screen\n";
        cout << "==============================\n";
        return;
    default:
        return;
    }
}

void showNoPermissionMessage()
{
    cout << "You don't have permission to use this service.\n";
    cout << "Talk with the Admin to let you in, thanks.\n";
}

void clientListScreen(short permission, string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enScreen::ClientsList);
    if (checkPermission(permission, enPermissions::ClientsList_pr))
        showAllClients(filePath, delim);
    else
        showNoPermissionMessage();
    showScreenBottom();
}

void addNewClientScreen(short permissions, string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enScreen::AddNewClient);
    if (checkPermission(permissions, enPermissions::AddNewClient_pr))
        addNewClient(filePath, delim);
    else
        showNoPermissionMessage();

    showScreenBottom();
}

void deleteClientScreen(short permissions, string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enScreen::DeleteClient);
    if (checkPermission(permissions, enPermissions::DeleteClient_pr))
    {
        string accountNumber;
        do
        {
            accountNumber = readString("Account Number: ");
        } while (accountNumber.length() != 4);
        deleteClientByAccountNumber(filePath, accountNumber, delim);
    }
    else
        showNoPermissionMessage();
    showScreenBottom();
}

void updateClientScreen(short permissions, string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enScreen::UpdateClient);
    if (checkPermission(permissions, enPermissions::UpdateClient_pr))
    {
        string accountNumber;
        do
        {
            accountNumber = readString("Account Number: ");
        } while (accountNumber.length() != 4);
        updateClientData(filePath, accountNumber, delim);
    }
    else
        showNoPermissionMessage();
    showScreenBottom();
}

void findClientScreen(short permissions, string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enScreen::FindClient);
    if (checkPermission(permissions, enPermissions::FindClient_pr))
    {
        string accountNumber;
        do
        {
            accountNumber = readString("Account Number: ");
        } while (accountNumber.length() != 4);
        printClientDataCardByAccountNumber(filePath, accountNumber, delim);
        cout << endl;
    }
    else
        showNoPermissionMessage();
    showScreenBottom();
}

void showTransactionsMainMenu()
{
    showScreenHeader(enScreen::Transactions);
    cout << "  [1] Deposit\n";
    cout << "  [2] Withdraw\n";
    cout << "  [3] Total Balances\n";
    cout << "  [4] Main Menu\n";
    cout << "==============================\n";
}

void showScreenHeader(enTransaction transaction)
{
    switch (transaction)
    {
    case enTransaction::Deposit:
        cout << " ===============================================\n";
        cout << "\t\tDeposit Screen\n";
        cout << " ===============================================\n";
        return;
    case enTransaction::Withdraw:
        cout << " ===============================================\n";
        cout << "\t\tWithdraw Screen\n";
        cout << " ===============================================\n";
        return;
    case enTransaction::TotalBalances:
        cout << " ===============================================\n";
        cout << "\t\tTotal Balances Screen\n";
        cout << " ===============================================\n";
        return;
    default:
        return;
    }
}

void depositScreen(string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enTransaction::Deposit);
    string accountNumber;
    do
    {
        accountNumber = readString("Account Number: ");
    } while (accountNumber.length() != 4);
    depositToClientBalance(accountNumber, filePath, delim);
    showScreenBottom();
}

void withdrawScreen(string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enTransaction::Withdraw);
    string accountNumber;
    do
    {
        accountNumber = readString("Account Number: ");
    } while (accountNumber.length() != 4);
    withdrawFromClientBalance(accountNumber, filePath, delim);
    showScreenBottom();
}

void totalBalancesScreen(string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enTransaction::TotalBalances);
    printClientsBalances(filePath, delim);
    cout << endl;
    showScreenBottom();
}

void startTransactionScreen(enTransaction& transaction, string filePath, string delim = "#//#")
{
    switch (transaction)
    {
    case enTransaction::Deposit:
        depositScreen(filePath, delim);
        break;
    case enTransaction::Withdraw:
        withdrawScreen(filePath, delim);
        break;
    case enTransaction::TotalBalances:
        totalBalancesScreen(filePath, delim);
        break;
    default:
        break;
    }
}

void transactionsScreen(short permissions, string filePath, string delim = "#//#")
{
    enTransaction transaction;
    if (checkPermission(permissions, enPermissions::Transactions_pr))
    {
        do
        {
            resetScreen();
            showTransactionsMainMenu();
            transaction = (enTransaction)funcs::readShortNumberInRange(1, 4, "What you want to do? [1 - 4]? ");
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            startTransactionScreen(transaction, filePath, delim);
        } while (transaction != enTransaction::ExitTransactions);
    }
    else
    {
        resetScreen();
        showScreenHeader(enScreen::Transactions);
        showNoPermissionMessage();
        showScreenBottom();
    }
}

void showManageUsersMainMenu()
{
    showScreenHeader(enScreen::ManageUsers);
    cout << "  [1] Users List\n";
    cout << "  [2] Add New User\n";
    cout << "  [3] Delete User\n";
    cout << "  [4] Update User\n";
    cout << "  [5] Find User\n";
    cout << "  [6] Main Menu\n";
    cout << "==============================\n";
}

void showScreenHeader(enManageUsers manageUser)
{
    switch (manageUser)
    {
    case enManageUsers::UsersList:
        cout << " ===============================================\n";
        cout << "\t\tUsers List Screen\n";
        cout << " ===============================================\n";
        return;
    case enManageUsers::AddNewUser:
        cout << " ===============================================\n";
        cout << "\t\tAdd New User Screen\n";
        cout << " ===============================================\n";
        return;
    case enManageUsers::DeleteUser:
        cout << " ===============================================\n";
        cout << "\t\tDelete User Screen\n";
        cout << " ===============================================\n";
        return;
    case enManageUsers::UpdateUser:
        cout << " ===============================================\n";
        cout << "\t\tUpdate User Screen\n";
        cout << " ===============================================\n";
        return;
    case enManageUsers::FindUser:
        cout << " ===============================================\n";
        cout << "\t\tFind User Screen\n";
        cout << " ===============================================\n";
        return;
    default:
        return;
    }
}

void UsersListScreen(string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enManageUsers::UsersList);
    showAllUsers(filePath, delim);
    showScreenBottom();
}

void addNewUserScreen(string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enManageUsers::AddNewUser);
    addNewUser(filePath, delim);
    showScreenBottom();
}

void deleteUserScreen(string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enManageUsers::DeleteUser);
    deleteUser(filePath, readString("username: "), delim);
    showScreenBottom();
}

void updateUserScreen(string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enManageUsers::UpdateUser);
    updateUser(filePath, readString("username: "), delim);
    showScreenBottom();
}

void findUserScreen(string filePath, string delim = "#//#")
{
    resetScreen();
    showScreenHeader(enManageUsers::UpdateUser);
    findUser(filePath, readString("username: "), delim);
    showScreenBottom();
}

void startManageUsersScreen(enManageUsers& manageUser, string filePath, string delim = "#//#")
{
    switch (manageUser)
    {
    case enManageUsers::UsersList:
        UsersListScreen(filePath, delim);
        break;
    case enManageUsers::AddNewUser:
        addNewUserScreen(filePath, delim);
        break;
    case enManageUsers::DeleteUser:
        deleteUserScreen(filePath, delim);
        break;
    case enManageUsers::UpdateUser:
        updateUserScreen(filePath, delim);
        break;
    case enManageUsers::FindUser:
        findUserScreen(filePath, delim);
        break;
    default:
        return;
    }
}

void manageUsersScreen(short permissions, string filePath, string delim = "#//#")
{
    enManageUsers manageUser;
    if (checkPermission(permissions, enPermissions::ManageUsers_pr))
    {
        do
        {
            resetScreen();
            showManageUsersMainMenu();
            manageUser = (enManageUsers)funcs::readShortNumberInRange(1, 6, "What you want to do? [1 - 6]? ");
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            startManageUsersScreen(manageUser, filePath, delim);
        } while (manageUser != enManageUsers::ExitManageUsers);
    }
    else
    {
        resetScreen();
        showScreenHeader(enScreen::ManageUsers);
        showNoPermissionMessage();
        showScreenBottom();
    }
}

void startScreen(short permissions, enScreen& screen, string filePath, string delim = "#//#")
{
    switch (screen)
    {
    case enScreen::ClientsList:
        clientListScreen(permissions, filePath, delim);
        break;
    case enScreen::AddNewClient:
        addNewClientScreen(permissions, filePath, delim);
        break;
    case enScreen::DeleteClient:
        deleteClientScreen(permissions, filePath, delim);
        break;
    case enScreen::UpdateClient:
        updateClientScreen(permissions, filePath, delim);
        break;
    case enScreen::FindClient:
        findClientScreen(permissions, filePath, delim);
        break;
    case enScreen::Transactions:
        transactionsScreen(permissions, filePath, delim);
        break;
    case enScreen::ManageUsers:
        manageUsersScreen(permissions, "Users.txt", delim);
        break;
    default:
        break;
    }
}

void showLoginScreenHeader()
{
    resetScreen();
    cout << " ===============================================\n";
    cout << "\t\tLogin Screen\n";
    cout << " ===============================================\n";
}

void startApp(short permissions, string filePath, string delim = "#//#")
{
    enScreen screen;
    do
    {
        resetScreen();
        showMainMenuScreen();
        screen = (enScreen)funcs::readShortNumberInRange(1, 8, "Choose what you want to do? [1 to 8]? ");
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        startScreen(permissions, screen, filePath, delim);
    } while (screen != enScreen::Logout);
    showLoginScreenHeader();
}

void login()
{
    string usersFilePath = "Users.txt";
    stUser user;
    showLoginScreenHeader();
    do
    {
        user.username = readString("username: ");
        user.password = readString("password: ");
        if (isUserFound(usersFilePath, user))
        {
            user = copyUserData(usersFilePath, user.username, "#//#");
            string filePath = "Bank.txt";
            startApp(user.permissions, filePath, "#//#");
        }
        else
            cout << "Invalid username/password\n";
    } while (true);
}

int main()
{
    login();

    return 0;
}