import pandas as pd

def csv_to_excel(csv_file, excel_file):
    # Read the CSV file
    data = pd.read_csv(csv_file)
    
    # Write to an Excel file
    data.to_excel(excel_file, index=False)

if __name__ == "__main__":
    # Specify the CSV file and the desired Excel file name
    csv_file = 'day.csv'  # Replace with your input CSV file name
    excel_file = 'days.xlsx'  # Replace with your desired output Excel file name
    
    # Convert CSV to Excel
    csv_to_excel(csv_file, excel_file)
    print(f"Converted {csv_file} to {excel_file}")
