import speech_recognition as sr
import pyttsx3
import datetime
import webbrowser
import os
import wikipedia
import time

# Initialize the text-to-speech engine
engine = pyttsx3.init()

# Set voice rate and volume
engine.setProperty('rate', 150)  # Speed of speech
engine.setProperty('volume', 0.9)  # Volume level (0.0 to 1.0)

# Function to make the assistant speak
def speak(text):
    engine.say(text)
    engine.runAndWait()

# Function to take voice input from the user
def take_command():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        recognizer.pause_threshold = 1  # Wait time for pause between commands
        audio = recognizer.listen(source)

    try:
        print("Recognizing...")
        query = recognizer.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")
    except Exception as e:
        print("Sorry, I didn't catch that. Can you repeat?")
        speak("Sorry, I didn't catch that. Can you repeat?")
        return None
    return query.lower()

# Function to greet the user based on the time of day
def greet_user():
    hour = datetime.datetime.now().hour
    if hour < 12:
        speak("Good morning!")
    elif 12 <= hour < 18:
        speak("Good afternoon!")
    else:
        speak("Good evening!")
    speak("I am JARVIS. How can I assist you today?")

# Function to tell the current date
def tell_date():
    today = datetime.datetime.now().strftime("%A, %d %B %Y")
    speak(f"Today is {today}.")

# Function to handle reminders (simple reminders stored in a list)
reminders = []
def set_reminder(reminder_text):
    reminders.append(reminder_text)
    speak("Reminder added.")

def show_reminders():
    if reminders:
        speak("Here are your reminders:")
        for reminder in reminders:
            speak(reminder)
    else:
        speak("You have no reminders.")

# Main function to handle commands
def jarvis():
    greet_user()
    unrecognized_count = 0  # Count unknown commands for feedback

    while True:
        query = take_command()

        if query is None:
            continue

        # Reset unknown command counter if a valid command is given
        unrecognized_count = 0

        # Logic to handle various commands
        if 'wikipedia' in query:
            speak("Searching Wikipedia...")
            query = query.replace('wikipedia', '')
            try:
                result = wikipedia.summary(query, sentences=2)
                speak(f"According to Wikipedia, {result}")
            except Exception as e:
                speak("Sorry, I couldn't find anything on Wikipedia.")

        elif 'open youtube' in query:
            webbrowser.open("https://www.youtube.com")
            speak("Opening YouTube.")

        elif 'open google' in query:
            webbrowser.open("https://www.google.com")
            speak("Opening Google.")

        elif 'open facebook' in query:
            webbrowser.open("https://www.facebook.com")
            speak("Opening Facebook.")

        elif 'open gmail' in query:
            webbrowser.open("https://mail.google.com")
            speak("Opening Gmail.")

        elif 'time' in query:
            current_time = datetime.datetime.now().strftime('%H:%M:%S')
            speak(f"The current time is {current_time}.")

        elif 'date' in query:
            tell_date()

        elif 'open code' in query:
            path = "C:\\Users\\<YourUsername>\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
            os.startfile(path)
            speak("Opening Visual Studio Code.")

        elif 'shutdown' in query:
            speak("Shutting down the system.")
            os.system("shutdown /s /t 1")

        elif 'restart' in query:
            speak("Restarting the system.")
            os.system("shutdown /r /t 1")

        elif 'set reminder' in query:
            speak("What should I remind you about?")
            reminder = take_command()
            if reminder:
                set_reminder(reminder)

        elif 'show reminders' in query:
            show_reminders()

        elif 'exit' in query or 'bye' in query:
            speak("Goodbye! Have a great day.")
            break

        else:
            unrecognized_count += 1
            speak("Sorry, I didn't understand that command.")
            # Provide feedback after 3 unrecognized commands
            if unrecognized_count == 3:
                speak("It seems like I am having trouble understanding your commands. Please try different phrases or check your microphone.")

# Run the JARVIS assistant
if __name__ == "__main__":
    jarvis()
