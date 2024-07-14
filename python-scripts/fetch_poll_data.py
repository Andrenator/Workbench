import requests
import csv
import json

API_KEY = '123'
BASE_URL = 'https://api.strawpoll.com/v3/polls/'

# Read poll IDs from the text file
with open('data-files\\poll_ids.txt', 'r') as file:
    poll_ids = file.read().split(',')

# Function to fetch poll data
def fetch_poll_data(poll_id):
    url = f'{BASE_URL}{poll_id}'
    headers = {
        'Accept': 'application/json',
        'X-API-Key': API_KEY
    }
    response = requests.get(url, headers=headers)
    return response.json()

# Fetch data for each poll
poll_data = []
for poll_id in poll_ids:
    print("Fetching", poll_id)
    data = fetch_poll_data(poll_id.strip())
    # print(data)
    poll_data.append(data)

# Create the CSV file
with open('generated-files\\poll_results.csv', 'w', newline='', encoding='utf-8') as csvfile:
    # Initialize CSV writer
    csv_writer = csv.writer(csvfile)
    
    # Write headers
    headers = ['Poll Title', 'Poll ID']
    # Add poll options as headers
    if poll_data:
        for entry in poll_data:
            poll_options = entry['poll_options']
            for option in poll_options:
                if option['value'] not in headers:
                    headers.append(option['value'])
    csv_writer.writerow(headers)
    
    # Write poll data
    for poll in poll_data:
        row = [poll['title'], poll['id']]
        option_vote_count = {option['value']: option['vote_count'] for option in poll['poll_options']}
        for header in headers[2:]:  # Skip 'Poll Title' and 'Poll ID' in headers
            row.append(option_vote_count.get(header, 0))  # Default to 0 if option not found in this poll
        csv_writer.writerow(row)

print("CSV file 'poll_results.csv' created successfully.")
