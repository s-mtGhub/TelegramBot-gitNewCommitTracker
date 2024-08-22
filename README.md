
---

# TelegramBot-gitNewCommitTracker

TelegramBot-gitNewCommitTracker is a C++ bot that sends notifications to your Telegram chat whenever new commits are pushed to your favorite GitHub repositories.

Inspired by [git_release_tracker](https://github.com/dracarys18/git_release_tracker) written in Rust by [dracarys18](https://github.com/dracarys18).

## Dependencies

To use this bot, you'll need the [telegram bot C++ API](https://github.com/reo7sp/tgbot-cpp). Install the dependencies with the following commands:

```bash
sudo apt-get install g++ make binutils cmake libssl-dev libboost-system-dev zlib1g-dev libcurl4-openssl-dev
git clone https://github.com/reo7sp/tgbot-cpp
cd tgbot-cpp
cmake .
make -j4
sudo make install
```

## Installation [from source folder 'tgbot-cpp/src']

1. **Clone the Repository**  
   Clone this repository and compile the source code:

   ```bash
   git clone https://github.com/s-mtGhub/TelegramBot-gitNewCommitTracker.git
   cd TelegramBot-gitNewCommitTracker
   make all
   ```

2. **Configure the Bot**  
   Rename the `config-sample.json` file to `config.json` and fill in the necessary details such as chat ID, token, and repositories to monitor:

   ```bash
   mv config-sample.json config.json
   ```

   Example `config.json`:

   ```json
   {
       "chat_id": "",     // Enter the chat ID to be notified
       "token": "",       // Enter your bot token (stored locally, so no need to worry)
       "repos": [         // Add the repositories you want to track
           "s-mtGhub/TelegramBot-gitNewCommitTracker",
           "torvalds/linux"
       ],
       "github_personal_token": ""  // Format: "<github_username>:token"
   }
   ```

3. **Obtain Telegram Bot Token and Chat ID**  
   - Get your bot token from Telegram by visiting [BotFather](https://t.me/botfather).
   - To find your chat ID, follow these steps:
     1. Start a conversation with your new Telegram bot.
     2. Send a message or click "Start."
     3. Open this URL in your browser: `https://api.telegram.org/bot<your_bot_token>/getUpdates`
     4. Look for the `chat.id` field in the JSON response to find your chat ID.

   Example URL:

   ```bash
   https://api.telegram.org/bot63xxxxxx71:AAFoxxxxn0hwA-2TVSxxxNf4c/getUpdates
   ```

   Example JSON response:

   ```json
   {
     "ok": true,
     "result": [
       {
         "update_id": 83xxxxx35,
         "message": {
           "message_id": 2643,
           "chat": {
             "id": 21xxxxx38,
             "username": "@username"
           },
           "text": "/start"
         }
       }
     ]
   }
   ```

   To test your setup, try sending a message:

   ```bash
   https://api.telegram.org/bot63xxxxxx71:AAFoxxxxn0hwA-2TVSxxxNf4c/sendMessage?chat_id=21xxxxx38&text=test123
   ```

   If everything is correct, you should receive the `test123` message in your Telegram bot chat.

4. **Run the Bot**  
   After filling in the chat ID and token, start the bot with:

   ```bash
   make run
   ```

   Or:

   ```bash
   cd bin && ./telegram_bot-github-release-tracker
   ```

## Customization

You can customize paths in the `config.h` header file and then recompile the project:

```cpp
// Configuration file path
#define CONFIG_PATH "../config.json"

// Temporary file path
#define TMP_FILE_PATH "/tmp/telegram-bot-cachedkjafldfklalg.json"

// Path of the folder where the latest version tag is stored
#define DATA_FOLDER_PATH "../data/"
```

## Important Notes

- The GitHub API allows up to 60 requests per hour without authentication. To increase this limit, generate a GitHub token from [here](https://github.com/settings/tokens).
- The `"github_personal_token"` should be in the format `"yourusername:token"`.

---