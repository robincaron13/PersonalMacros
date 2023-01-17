import requests

url = "https://www.nseindia.com/api/option-chain-indices?symbol=NIFTY"
payload = {}
headers = {}

try:
    response = requests.request("GET", url, headers=headers, data=payload)
    response.raise_for_status()
    print(response.text.encode('utf8'))
except requests.HTTPError as exception:
    print("exception occurred", exception)

error : requests.exceptions.ReadTimeout: HTTPSConnectionPool(host='www.nseindia.com', port=443): Read timed out. (read timeout=None)
