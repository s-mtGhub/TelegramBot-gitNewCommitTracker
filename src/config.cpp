/**
 
 */ 
#include "config.h"

void json2config(nlohmann::json &j, struct config_t &conf)
{
    j.at("chat_id").get_to(conf.chat_id);
    j.at("token").get_to(conf.token);
    for (auto &element : j["repos"])
    {
        conf.repos.push_back(element.get<std::string>());
    }
    j.at("github_personal_token").get_to(conf.personal_token);
}

void get_config(struct config_t &conf)
{
    std::ifstream conf_in(CONFIG_PATH);
    if (!conf_in.is_open())
    {
        conf_in.close();
        std::ofstream conf_out(CONFIG_PATH);
        if (conf_out.is_open())
        {
            conf_out << R"V0G0N({
    "chat_id": "",
    "token": "",
    "repos": [
        "s-mtGhub/TelegramBot-gitNewCommitTracker",
        "torvalds/linux"
    ],
    "github_personal_token": ""
}
)V0G0N";
        }
        else
        {
            std::cerr << "telgram-bot : cannot access \'" << CONFIG_PATH << "\' : " << strerror(errno) << '\n';
            exit(1);
        }
        conf_out.close();
        conf_in.open(CONFIG_PATH);
    }

    conf.repos.clear();
    if (conf_in.is_open())
    {
        nlohmann::json config_json;
        conf_in >> config_json;
        json2config(config_json, conf);
        conf_in.close();
    }
    else
    {
        conf_in.close();
        std::cerr << "telgram-bot : cannot access \'" << CONFIG_PATH << "\' : " << strerror(errno) << '\n';
        exit(1);
    }
}
