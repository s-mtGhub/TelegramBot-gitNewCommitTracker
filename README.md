# Telegram Bot
This is Telegram bot written in C++, it will send message in telegram when there is new commit pushed from your favorite repo in github.    
This program is inspired from [git_release_tracker](https://github.com/dracarys18/git_release_tracker) written in rust by [dracarys18](https://github.com/dracarys18)

# Dependency 
It needs [telegram bot c++ api](https://github.com/reo7sp/tgbot-cpp).    
Install that using below commands
```sh
sudo apt-get install g++ make binutils cmake libssl-dev libboost-system-dev zlib1g-dev libcurl4-openssl-dev
git clone https://github.com/reo7sp/tgbot-cpp
cd tgbot-cpp
cmake .
make -j4
sudo make install
```

# Install from source [tgbot-cpp/src]
Clone this repo and compile.
```sh
git clone https://github.com/s-mtGhub/TelegramBot-gitNewCommitTracker.git
cd TelegramBot-gitNewCommitTracker
make all
```
Rename config-sample.json to config.json and fill the chat id, token,repos to be monitored    

`mv config-sample.json config.json`
```json
{
    "chat_id": "",     // Enter the chat id to be notified
    "token": "",       // Enter your bot token(stored locally,so don't have to worry)
    "repos": [         // add the repos you want to track
        "ms-jagadeeshan/TelegramBot-gitNewCommitTracker",
        "torvalds/linux"
    ],
    "github_personal_token":""  // Format:  "<github_username>:token"
}
```
Go to telegram and https://t.me/botfather to get bot token from telegram.    
get you chat id : 
1. Search and open our new Telegram bot
2. Click Start or send a message
3. Open this URL in a browser https://api.telegram.org/bot{our_bot_token}/getUpdates
4. See we need to prefix our token with a word bot
Eg: https://api.telegram.org/bot63xxxxxx71:AAFoxxxxn0hwA-2TVSxxxNf4c/getUpdates
5. We will see a json like so
{
  "ok": true,
  "result": [
    {
      "update_id": 83xxxxx35,
      "message": {
        "message_id": 2643,
        "from": {...},
        "chat": {
          "id": 21xxxxx38,
          "first_name": "...",
          "last_name": "...",
          "username": "@username",
          "type": "private"
        },
        "date": 1703062972,
        "text": "/start"
      }
    }
  ]
}
6. Check the value of result.0.message.chat.id, and here is our Chat ID: 21xxxxx38
7. Let's try to send a message: https://api.telegram.org/bot63xxxxxx71:AAFoxxxxn0hwA-2TVSxxxNf4c/sendMessage?chat_id=21xxxxx38&text=test123
When we set the bot token and chat id correctly, the message test123 should be arrived on our Telegram bot chat.    
After filling chat id and token just run this to start the bot
```sh
make run
# or
# cd bin && ./telegram_bot-github-release-tracker
```

# Customizing
In [config.h](./include/config.h) header file paths are defined, you can change them and compile
```c++
// Configuration file path
#define CONFIG_PATH "../config.json"

// Temporary file path
#define TMP_FILE_PATH "/tmp/telegram-bot-cachedkjafldfklalg.json"

// Path of folder, where latest version tag stored
#define DATA_FOLDER_PATH "../data/"
```

# Things to be noted
- We can use github api only 60 times a hour without github user authentication. So generate your github token from [here](https://github.com/settings/tokens)
- Note `"github_personal_token"` should be filled in the format of `"yourusername:token"`

# TelegramBot-gitNewCommitTracker
