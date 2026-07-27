const worker = new Worker("worker.js");

worker.postMessage("Fetch Users");

worker.onmessage = function (event) {

    if (event.data.success) {

        const users = event.data.data;

        users.forEach(user => {

            console.log(
                `${user.name} - ${user.active ? "Active" : "Inactive"}`
            );

        });

    }
    else {

        console.error(event.data.message);

    }

};

worker.onerror = function () {

    console.error("Web Worker Error");

};
