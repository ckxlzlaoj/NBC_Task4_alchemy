#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// PotionRecipe Ŭ����: ��� ����� vector<string>���� ����
class PotionRecipe {
public:
    string potionName;
    vector<string> ingredients; // ���� ��ῡ�� ��� '���'���� ����

    // ������: ��� ����� �޾� �ʱ�ȭ�ϵ��� ����
    PotionRecipe(const string& name, const vector<string>& ingredients)
        : potionName(name), ingredients(ingredients) {}

};

// AlchemyWorkshop Ŭ����: ������ ����� ����
class AlchemyWorkshop {
private:
    vector<PotionRecipe> recipes;

public:
    // addRecipe �޼���: ��� ���(vector)�� �Ű������� �޵��� ����
    void addRecipe(const string& name, const vector<string>& ingredients) {
        recipes.push_back(PotionRecipe(name, ingredients));
        cout << ">> ���ο� ������ '" << name << "'��(��) �߰��Ǿ����ϴ�." << endl;
    }

    // ��� ������ ��� �޼���
    void displayAllRecipes() const {
        if (recipes.empty()) {
            cout << "���� ��ϵ� �����ǰ� �����ϴ�." << endl;
            return;
        }

        cout << "\n--- [ ��ü ������ ��� ] ---" << endl;
        for (size_t i = 0; i < recipes.size(); ++i) {
            cout << "- ���� �̸�: " << recipes[i].potionName << endl;
            cout << "  > �ʿ� ���: ";

            // ��� ����� ��ȸ�ϸ� ���
            for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
                cout << recipes[i].ingredients[j];
                // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
                if (j < recipes[i].ingredients.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
        cout << "---------------------------\n";
    }
    PotionRecipe* searchRecipeByName(string& name)
    {
        bool find = false;

        for (auto& PotionRecipe_ : recipes)
        {
            if (PotionRecipe_.potionName == name)
            {
                find = true;
                cout << endl;
                cout << "- ���� �̸�: " << PotionRecipe_.potionName << endl;
                cout << "  > �ʿ� ���: ";
                for (auto PotionRecipe_ing : PotionRecipe_.ingredients)
                {
                    cout << PotionRecipe_ing<<" ";

                }
            }
        }
        if (find) {
            cout << endl;
            return 0;
        }
        else {
            cout << "���� �̸����� ã������" << endl;
        }
    };

    PotionRecipe* searchRecipeByIngredient(string ingredient)
    {

        bool find=false;
        for (auto& PotionRecipe_ : recipes)
        {
            for (auto PotionRecipe_ing : PotionRecipe_.ingredients)
            {
                if (PotionRecipe_ing == ingredient)
                {
                    find = true;
                    cout << endl;
                    cout << "- ���� �̸�: " << PotionRecipe_.potionName << endl;
                    cout << "  > �ʿ� ���: ";
                }
                cout <<  PotionRecipe_ing << " ";

            }
        }
        if (find) {
            cout << endl;
            return 0;
        }
        else {
            cout << "���� ��ᰡ ���Ե� ������ ã������" << endl;
        }
        
    };
};
int main() {
    AlchemyWorkshop myWorkshop;

    while (true) {
        cout << endl;
        cout << "# ���ݼ� ���� ���� �ý���" << endl;
        cout << "1. ������ �߰�" << endl;
        cout << "2. ��� ������ ���" << endl;
        cout << "3. ���� �̸� �˻�" << endl;
        cout << "4. ���� ��ᰡ ���Ե� ������" << endl;
        cout << "5. ����" << endl;
        cout << "����: ";

        int choice;
        cin >> choice;
        string search;
        if (cin.fail()) {
            cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            string name;
            cout << "���� �̸�: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            // ���� ��Ḧ �Է¹ޱ� ���� ����
            vector<string> ingredients_input;
            string ingredient;
            cout << "�ʿ��� ������ �Է��ϼ���. (�Է� �Ϸ� �� '��' �Է�)" << endl;

            while (true) {
                cout << "��� �Է�: ";
                getline(cin, ingredient);

                // ����ڰ� '��'�� �Է��ϸ� ��� �Է� ����
                if (ingredient == "��") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // �Է¹��� ��ᰡ �ϳ� �̻� ���� ���� ������ �߰�
            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else {
                cout << ">> ��ᰡ �Էµ��� �ʾ� ������ �߰��� ����մϴ�." << endl;
            }

        }
        else if (choice == 2) {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3) {
            cout << "���� �̸� �Է�: ";
            cin>>search;
            myWorkshop.searchRecipeByName(search);

        }
        else if (choice == 4) {
            cout << "��� �̸� �Է�: ";
            cin >> search;
            myWorkshop.searchRecipeByIngredient(search);

        }
        else if (choice == 5) {
            cout << "���� ���� �ݽ��ϴ�..." << endl;
            break;

        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
};