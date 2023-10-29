#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <vector>

class Contact : public CppAppContainer
{
    public:
    void main();
    
    static void loadContacts(bool force = false);
    static void saveContacts();
    static uint16_t contactPage();
    static void editContact(bool create = false, uint16_t index = -1);
    static void showContact(uint16_t index);

    struct OneContact
    {
        std::string name;
        std::string number;
    };

    static std::vector<OneContact> contacts;
};

std::vector<Contact::OneContact> Contact::contacts = {};


#endif