import addressbook_pb2

def func():
    person = addressbook_pb2.Person()
    person.id = 1234
    person.name = "John Doe"
    person.email = "jdoe@example.com"
    phone = person.phones.add()
    phone.number = "555-4321"
    phone.type = addressbook_pb2.Person.PHONE_TYPE_HOME
    print(person.IsInitialized())
    print(person.__str__())

def main():
    func()

if __name__ == "__main__":
    main()