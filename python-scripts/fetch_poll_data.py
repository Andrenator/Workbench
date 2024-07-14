import requests
import csv
import json

# Replace 'YOUR_API_KEY' with your actual API key
API_KEY = 'YOUR_API_KEY'
BASE_URL = 'https://api.strawpoll.com/v3/polls/'

# Read poll IDs from a text file
with open('poll_ids.txt', 'r') as file:
    poll_ids = file.read().split(',')

# Function to fetch poll data
def fetch_poll_data(poll_id):
    url = f'{BASE_URL}{poll_id}/results'
    headers = {
        'Accept': 'application/json',
        'X-API-Key': API_KEY
    }
    response = requests.get(url, headers=headers)
    return response.json()

# Fetch data for each poll
poll_data = []
for poll_id in poll_ids:
    data = fetch_poll_data(poll_id.strip())
    poll_data.append(data)

# Create the CSV file
with open('poll_results.csv', 'w', newline='', encoding='utf-8') as csvfile:
    # Initialize CSV writer
    csv_writer = csv.writer(csvfile)
    
    # Write header
    headers = ['Poll Title', 'Poll ID']
    # Add poll options as headers
    if poll_data:
        poll_options = poll_data[0]['poll_options']
        for option in poll_options:
            headers.append(option['value'])
    csv_writer.writerow(headers)
    
    # Write poll data
    for poll in poll_data:
        row = [poll['title'], poll['id']]
        for option in poll['poll_options']:
            row.append(option['vote_count'])
        csv_writer.writerow(row)

print("CSV file 'poll_results.csv' created successfully.")
