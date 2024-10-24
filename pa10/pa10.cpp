#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

class Employee {
public:
    std::string name;
    std::string email;
    std::string role;
    std::string group_id;

    Employee() {}

    Employee(std::string name, std::string email, std::string role, std::string group_id = "")
        : name(name), email(email), role(role), group_id(group_id) {}

    friend std::ostream& operator<<(std::ostream& os, const Employee& emp) {
        os << "Employee Name: " << emp.name << ", Email: " << emp.email << ", Role: " << emp.role << ", Group ID: " << emp.group_id << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Employee& emp) {
        std::cout << "Enter employee name: ";
        is >> emp.name;
        std::cout << "Enter employee email: ";
        is >> emp.email;
        std::cout << "Enter employee role: ";
        is >> emp.role;
        return is;
    }
};

class Group {
public:
    std::string name;
    std::string group_id;
    std::string responsibility;
    std::vector<Employee> employees;

    Group() {}

    Group(std::string name, std::string group_id, std::string responsibility)
        : name(name), group_id(group_id), responsibility(responsibility) {}

    void add_employee(Employee emp) {
        emp.group_id = group_id;
        employees.push_back(emp);
    }

    Group operator-(int num_employees) {
        if (num_employees > employees.size()) {
            std::cerr << "Can't remove more employees than present in the group." << std::endl;
            return *this;
        }
        std::shuffle(employees.begin(), employees.end(), std::default_random_engine(std::time(0)));
        employees.resize(employees.size() - num_employees);
        return *this;
    }

    Group operator+(const Group& other) {
        Group new_group(name + "-" + other.name, group_id + "-" + other.group_id, responsibility + ", " + other.responsibility);
        new_group.employees = employees;
        new_group.employees.insert(new_group.employees.end(), other.employees.begin(), other.employees.end());
        for (auto& emp : new_group.employees) {
            emp.group_id = new_group.group_id;
        }
        return new_group;
    }

    friend std::ostream& operator<<(std::ostream& os, const Group& group) {
        os << "Group Name: " << group.name << ", ID: " << group.group_id << ", Responsibility: " << group.responsibility << ", Employees:\n";
        for (const auto& emp : group.employees) {
            os << emp << "\n";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Group& group) {
        std::cout << "Enter group name: ";
        is >> group.name;
        std::cout << "Enter group ID: ";
        is >> group.group_id;
        std::cout << "Enter group responsibility: ";
        is >> group.responsibility;
        return is;
    }
};

int main() {
    Group group1("G", "G1", "Sales");
    Group group2("X", "G2", "Marketing");

    Employee emp1("Joe Bob", "joebob@gmail.com", "Sales Manager");
    Employee emp2("Jane Smith", "jane@gmail.com", "Sales Executive");
    Employee emp3("Jim Brown", "jim@gmail.com", "Marketing Manager");
    Employee emp4("Jake White", "jake@gmail.com", "Marketing Executive");

    group1.add_employee(emp1);
    group1.add_employee(emp2);
    group2.add_employee(emp3);
    group2.add_employee(emp4);

    std::cout << "Initial Groups:" << std::endl;
    std::cout << group1 << std::endl;
    std::cout << group2 << std::endl;

    std::cout << "\nGroup G loses 1 employee:" << std::endl;
    group1 = group1 - 1;
    std::cout << group1 << std::endl;

    std::cout << "\nMerging Group G and Group X:" << std::endl;
    Group merged_group = group1 + group2;
    std::cout << merged_group << std::endl;

    return 0;
}