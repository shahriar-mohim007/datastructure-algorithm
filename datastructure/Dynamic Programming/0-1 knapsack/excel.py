import openpyxl
from datetime import date, timedelta

# Create a new Excel workbook and select the default sheet
workbook = openpyxl.Workbook()
sheet = workbook.active

# Define the initial date and project name
start_date = date(2023, 10, 21)
project_name = "Task Station 23"

# Define the total hours
total_hours = 8

# Write headers
headers = ["Date", "Day", "Project Name", "Task Name", "Task Description", "Total Hour"]
sheet.append(headers)

# Generate data for each day from September 21, 2023, to October 20, 2023
current_date = start_date
end_date = date(2023, 11, 20)
while current_date <= end_date:
    day_of_week = current_date.strftime("%A")
    row_data = [current_date, day_of_week, project_name, "", "", total_hours]
    sheet.append(row_data)
    current_date += timedelta(days=1)

# Save the workbook to a file
workbook.save("task_schedule.xlsx")
