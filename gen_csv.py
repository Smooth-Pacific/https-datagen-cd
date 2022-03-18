from faker import Faker
import csv
import ccard
import random

def make_user():
    fake = Faker()

    header = ['user_id', 'f_name', 'l_name', 'email']

    with open('csv/users.csv', 'w') as f:
        writer = csv.writer(f)
        writer.writerow(header)
        
        for user_id in range(2000):
            f_name = fake.first_name()
            l_name = fake.last_name()
    
            data = [user_id, f_name, l_name, f'{f_name}.{l_name}@smoothceeplusplus.com'.replace(' ', '')]
    
            writer.writerow(data)

def get_num_of_cards_per_user():
    total_cards = 0
    with open('csv/cc.csv', 'w') as f2:
        writer = csv.writer(f2)
        writer.writerow(['user_id', 'num_of_cards'])
        with open('csv/card_transaction.v1.csv', 'r') as f1:
            csv_reader = csv.DictReader(f1)
            user_id = 0
            card_id = []

            for row in csv_reader:
                if user_id == int(row['User']):
                    card_id.append(int(row['Card'])+1)
                else:
                    total_cards += int(max(card_id))

                    data = [user_id, max(card_id)]
                    writer.writerow(data)
                    card_id.clear()

                    user_id = int(row['User'])
            total_cards += int(max(card_id))
            data = [user_id, max(card_id)]
            writer.writerow(data)
            card_id.clear()
            user_id = int(row['User'])


def generate_cc():
    with open('csv/credit_card.csv', 'w') as f2:
        writer = csv.writer(f2)
        writer.writerow(['cc_id', 'cc_num'])

        num_cards = 0
        with open('csv/cc.csv', 'r') as f1:
            csv_reader = csv.DictReader(f1)

            for row in csv_reader:
                num_cards += int(row['num_of_cards'])   

        for i in range(num_cards):
            rand_num = random.randrange(0, 4, 1)
            if rand_num == 0:
                writer.writerow([i, ccard.visa()])
            if rand_num == 1:
                writer.writerow([i, ccard.discover()])
            if rand_num == 2:
                writer.writerow([i, ccard.mastercard()])
            if rand_num == 3:
                writer.writerow([i, ccard.americanexpress()])

def generate_credit_card_user():
    with open('csv/credit_card_user.csv', 'w') as f1:
        writer = csv.writer(f1)
        writer.writerow(['card_id', 'user_id', 'cc_id'])

        card_id = 0
        with open('csv/cc.csv', 'r') as f2:
            csv_reader = csv.DictReader(f2)
            line_count = 0
            for row in csv_reader:
                for i in range(int(row['num_of_cards'])):
                    data = [card_id, row['user_id'], i]
                    writer.writerow(data)
                    card_id += 1
                    line_count += 1
            #print(line_count)



def generate_merchant():
    fake = Faker()

    with open('csv/merchants.csv', 'w') as f1:
        writer = csv.writer(f1)
        writer.writerow(['merch_id', 'merch_name', 'business_cat_id'])

        merch_set = set([])
        with open('csv/card_transaction.v1.csv', 'r') as f2:
            csv_reader = csv.DictReader(f2)

            for row in csv_reader:
                merch_set.add(int(row['Merchant Name']))
        
        for merch in merch_set:
            rand_num = random.randrange(0, 4, 1)

            writer.writerow([merch, fake.company().replace(',', ''), rand_num])


if __name__ == "__main__":
    make_user()
    get_num_of_cards_per_user()
    generate_cc()
    generate_credit_card_user()
    generate_merchant()

