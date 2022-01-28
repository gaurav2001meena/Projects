const Discord = require("discord.js")
const client = new Discord.Client({ intents: 32767 });
client.aliases = new Discord.Collection();

client.on("ready", () => {
    console.log("Bot is online!")
})

client.on("messageCreate", (message) => {
    const prefix = "-"
    if (!message.content.startsWith(prefix)) return;

    const messageArray = message.content.split(" ");
    const cmd = messageArray[0]
    const args = messageArray.slice(1);

    if (message.content.toLowerCase() === `${prefix}test`) {
        message.channel.send("The Bot is Working")
    }

    if (cmd.toLowerCase() === `${prefix}kick`) {
        if (!args[0]) return message.reply("You need to put someone in this command!")
        let member = message.mentions.members.first() || message.guild.members.cache.get(args[0]) || message.guild.members.cache.find(x => x.user.username.toLowerCase() === args.slice(0).join(" ") || x.user.username === args[0]);
        if (!message.member.permissions.has("KICK_MEMBERS")) return message.reply("Where is your permission bro...");
        if (!message.guild.me.permissions.has("KICK_MEMBERS")) return message.reply("I don't have permission to kick people!");
        if (message.member.id === member.id) return message.reply("You can't kick yourself...");

        member.kick()
        message.channel.send(`${member} just got kicked.`)
    }

    if (cmd.toLowerCase() === `${prefix}ban`) {
        if (!args[0]) return message.reply("You need to put someone in this command!")
        let member = message.mentions.members.first() || message.guild.members.cache.get(args[0]) || message.guild.members.cache.find(x => x.user.username.toLowerCase() === args.slice(0).join(" ") || x.user.username === args[0]);
        if (!message.member.permissions.has("BAN_MEMBERS")) return message.reply("Where is your permission bro...");
        if (!message.guild.me.permissions.has("BAN_MEMBERS")) return message.reply("I don't have permission to ban people!");
        if (message.member.id === member.id) return message.reply("You can't ban yourself...");

        let reason = args.slice(1).join(" ") || "No reason"

        member.ban({ reason:reason })
        message.channel.send(`${member} just got banned.\nReason: ${reason}`)
    }


})
module.exports = {
	name: 'timeout',
	aliases: [],
	execute: async (client, message, args) => {
		const fetch = require('node-fetch');
		const ms = require('ms');
		const time = args.slice(1).join(' ');

		if(!time) return message.channel.send('please specify the time!');

		const user = message.mentions.users.first();
		const milliseconds = ms(time);

		if(!user) return message.channel.send('no user specified');
		if(!milliseconds || milliseconds < 10000 || milliseconds > 2419200000) {
			return message.channel.send('invalid time or it isn\'t 10s-28d');
		}

		const iosTime = new Date(Date.now() + milliseconds).toISOString();

		await fetch(`https://discord.com/api/guilds/${message.guild.id}/members/${user.id}`, {
			method: 'PATCH',
			body: JSON.stringify({ communication_disabled_until: iosTime }),
			headers: {
				'Content-Type': 'application/json',
				'Authorization': `Bot ${client.token}`,
			},
		});
		message.channel.send(`${user.username} has been timed out for \`${time}\`!`);
	


       

client.login("OTMyNjgwMDQ3ODA5MTQ2OTMx.YeWf-w.dos5YrQX7JN8JsQTduGjZxy-ZJg")

