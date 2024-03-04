import requests
import json
import datetime
db = "erp"
baseUrl = "bs-23.com"
protocol = "https"
requestBase = f"{protocol}://{db}.{baseUrl}/"
email = "Nasif.Shahriar@brainstation-23.com"
password = "aHtndFhuVs7u9tM"

def odoo_authentication():
    request_url = requestBase + "web/session/authenticate"
    request_body = {
            "params": {
                "db": db,
                "login": email,
                "password": password
            }
        }
    
    headers = {
        "Content-Type": "application/json"
    }
    
    response = requests.post(request_url, json=request_body, headers=headers)

    authentication_response = response.json()
    #print(response.status_code)

    return authentication_response

def get_odoo_project(session_id):
    request_url = requestBase + "api/v1/projects"
    headers = {
        "Cookie": f"session_id={session_id}"
    }
    response = requests.get(request_url, headers=headers)
    response = json.dumps(response.json(), indent=4)
    print(response)

    return response
    
def get_employee_by_uid(session_id, erp_uid):
    request_url = f"{requestBase}api/v1/employees?user_ids=[{erp_uid}]"
    
    headers = {
        "Cookie": f"session_id={session_id}"
    }

    response = requests.get(request_url, headers=headers)
    employee_response = response.json()
    
    return employee_response


def create_erp_task(session_id, erp_user_id, erp_project_id, task_title):
    request_url = f"{requestBase}api/v1/task"
    
    params = {
        "project_id": 705,
        "name": task_title
        # "user_id": 1103,
    }
    
    headers = {
        "Cookie": f"session_id={session_id}"
    }
    
    try:
        response = requests.post(request_url, params=params, headers=headers)
        # Raise an exception for non-2xx HTTP responses
        
        res_struct =  response = json.dumps(response.json(), indent=4)
        return res_struct
    except requests.exceptions.RequestException as e:
        raise Exception(f"Error in request: {e}")


def get_user_time_sheet(session_id, erp_employee_id):
    request_url = f"{requestBase}api/v1/timesheet?employee_id={erp_employee_id}"

    headers = {
        "Cookie": f"session_id={session_id}"
    }

    try:
        response = requests.get(request_url, headers=headers)

        if response.status_code != 200:
            raise Exception(f"Error from Odoo ERP: {response.status_code}")

        response_json = json.dumps(response.json(), indent=4)
        return response_json

    except Exception as e:
        print(f"Error: {str(e)}")
        return None




import requests
import json

def update_timesheet(existing_scrum, session_id, description, task_description, spent_time_sec):
    # Calculate total time in hours and minutes

    data = {
    'project_id': '705',
    'time': '8.57',
    'task_id': 35912,
    'description': '<table style="border-collapse: collapse; width: 100%;">\n    <tr style="background-color: lightgray;">\n        <th style="text-align: center; padding: 10px;">Title</th>\n        <th style="text-align: center; padding: 10px;">Project</th>\n        <th style="text-align: center; padding: 10px;">Spent Time</th>\n        <th style="text-align: center; padding: 10px;">Tag</th>\n    </tr>\n    <tr style="border-bottom: 1px solid lightgray;">\n        <td style="text-align: center; padding: 10px;">TS-513-created_date field in Task api</td>\n        <td style="text-align: center; padding: 10px;">Task Station 23</td>\n        <td style="text-align: center; padding: 10px;">1:37:00</td>\n        <td style="text-align: center; padding: 10px;">Development</td>\n        <td style="display: none;">Hidden data</td> <!-- Hidden <td> -->\n',
    'task_description': 'Task Station 23'
}

# Now you have the data in the 'data' variable.


# Now you have the data in the 'data' variable.



    total_time = spent_time_sec / 3600  # Convert seconds to hours
    request_url = f"{requestBase}api/v1/timesheet/{existing_scrum['ID']}"
    params = {
        "project_id": data['project_id'],
        "time": data['time'],  # Format total_time as a float with 2 decimal places
        "task_id": data['task_id'],
        "description": data['description'],
        "task_description": data['task_description']
    }

    # Create a session and set the session ID cookie
    session = requests.Session()
    session.cookies.set("session_id", session_id)

    try:
        # Send the PATCH request
        response = session.patch(request_url, params=params)
        print(response)

        # Check the response status code
        if response.status_code != 200:
            raise Exception(f"Error updating ERP timesheet: {response.text}")

        # Parse the JSON response
        response_json = response.json()
        return response_json

    except Exception as e:
        raise Exception(f"Error updating ERP timesheet: {str(e)}")

session_id = "2adae517d0c17c803622b9fda9fbcfb2c45a2802"
existing_scrum = {
    "ID": 498902,
    "ProjectID": [705],
    "TaskID": [35912]
}
description = html_table = """
<table style="border-collapse: collapse; width: 100%;">
    <tr style="background-color: lightgray;">
        <th style="text-align: center; padding: 10px;">Title</th>
        <th style="text-align: center; padding: 10px;">Project</th>
        <th style="text-align: center; padding: 10px;">Spent Time</th>
        <th style="text-align: center; padding: 10px;">Tag</th>
    </tr>
    <tr style="border-bottom: 1px solid lightgray;">
        <td style="text-align: center; padding: 10px;">TS-513-created_date field in Task api</td>
        <td style="text-align: center; padding: 10px;">Task Station 23</td>
        <td style="text-align: center; padding: 10px;">00:34:00</td>
        <td style="text-align: center; padding: 10px;">Development</td>
        <td style="display: none;">Hidden data</td> <!-- Hidden <td> -->
    </tr>
    <tr style="border-bottom: 1px solid lightgray;">
        <td style="text-align: center; padding: 10px;">TS-510-Add project filter on `task-insight` api.</td>
        <td style="text-align: center; padding: 10px;">Task Station 23</td>
        <td style="text-align: center; padding: 10px;">02:20:00</td>
        <td style="text-align: center; padding: 10px;">Development</td>
        <td style="display: none;">Hidden data</td> <!-- Hidden <td> -->
    </tr>
    <tr style="border-bottom: 1px solid lightgray;">
        <td style="text-align: center; padding: 10px;">Task Station Daily Stand Up</td>
        <td style="text-align: center; padding: 10px;">Task Station 23</td>
        <td style="text-align: center; padding: 10px;">00:20:00</td>
        <td style="text-align: center; padding: 10px;">Meeting</td>
        <td style="display: none;">Hidden data</td> <!-- Hidden <td> -->
    </tr>
</table>
"""

task_description = "Updated task description"
spent_time_sec = 3600

try:
    response = update_timesheet(existing_scrum, session_id, description, task_description, spent_time_sec)
except Exception as e:
    print(f"Error: {str(e)}")

auth_response=odoo_authentication()
project_response=get_odoo_project(auth_response['result']['session_id'])
employee_response=get_employee_by_uid(auth_response['result']['session_id'],auth_response['result']['uid'])
erp_task_response=create_erp_task(auth_response['result']['session_id'],auth_response['result']['uid'],employee_response['employee_data'][0]['project_id'],'TS-484-ERP_Intrigration')
get_employee_by_uid(auth_response['result']['session_id'],1102)
get_user_time_sheet(auth_response['result']['session_id'],1079)

